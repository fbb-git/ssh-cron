#include "daemon.ih"

void Daemon::daemonize()
{
    string const &ipcFile = d_options.ipcFile();

    if (access(ipcFile.c_str(), F_OK) == 0)
        fmsg << ipcFile << " is in the way. Remove it first" << endl;

    createIPCfile();            // create it with access mode 0600
    
    d_shmem = SharedMemory(1, SharedMemory::kB);// create the shared memory

    streamsize pos;                             // create the shared condition
    SharedCondition::create(&pos, d_shmem);

    if (pos != 0)
    {
        d_shmem.kill();
        unlink(ipcFile.c_str());

        fmsg << "Daemon::daemonize internal error: "
                                        "SharedCondition not at 0" << endl;
    }

    fork();
}




