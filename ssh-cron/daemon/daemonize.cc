#include "daemon.ih"

void Daemon::daemonize()
{
    string const &ipcFile = d_options.ipcFile();

    if (access(ipcFile.c_str(), F_OK) == 0)
        fmsg << ipcFile << " is in the way. Remove it first" << endl;

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




