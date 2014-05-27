#include "daemon.ih"

void Daemon::parentProcess()
{
    if (not d_options.daemon())
        return;

    SharedMemory shmem(1, SharedMemory::kB);

    streamsize pos;
    SharedCondition::create(&pos, shmem);

    if (pos != 0)
        fmsg << "internal error: SharedCondition not at 0" << endl;

    // write the daemon's ipc-file:
    ofstream ipcFile;
    Exception::open(ipcFile, Options::instance().ipcFile());

    ipcFile << (d_shmemId = shmem.id()) << endl;
}















