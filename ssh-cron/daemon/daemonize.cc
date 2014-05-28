#include "daemon.ih"

void Daemon::daemonize()
{
    if (access(d_options.ipcFile().c_str(), F_OK))
        fmsg << d_options.ipcFile() << " is in the way. Remove it first" <<
                endl;

    createIPCfile();            // create it with access mode 0600
    
    ofstream ipcFile;           // open the daemon's ipc-file:
    Exception::open(ipcFile, Options::instance().ipcFile());

    SharedMemory shmem(1, SharedMemory::kB);    // create the shared memory

    streamsize pos;                             // create the shared condition
    SharedCondition::create(&pos, shmem);

    if (pos != 0)
    {
        shmem.kill();
        fmsg << "Daemon::daemonize internal error: "
                                        "SharedCondition not at 0" << endl;
    }

    ipcFile << (d_shmemId = shmem.id()) << endl;

    fork();
}
