#include "daemon.ih"

void Daemon::daemonize()
{
    string const &ipcFile = d_options.ipcFile();

    if (access(ipcFile.c_str(), F_OK) == 0)
    {
        bool remove = d_options.forced();

        if (not remove)
        {
            wmsg << ipcFile << " is in the way. Remove it [Ny]? ";
            string answer;
    
            remove = getline(cin, answer) 
                        && (answer == "y" || answer == "yes");
        }

        if (not remove or unlink(ipcFile.c_str()) != 0)
            fmsg << "cannot continue as " << ipcFile << 
                                            " cannot be removed " << endl;
    }

    getPassPhrase();


    createIPCfile();            // create it with access mode 0600,
                                // parentProcess() writes information to it

    d_shmem = SharedMemory(1, SharedMemory::kB);// create the shared memory

    try
    {
        SharedCondition::create(d_shmem);  // create the shared condition
    }
    catch (exception const &exc)
    {
        unlink(ipcFile.c_str());
        throw;
    }

    idmsg() << "starting the daemon" << endl;
    fork();
}






