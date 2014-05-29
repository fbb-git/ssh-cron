#include "daemon.ih"

size_t Daemon::getSharedMemory()
{
    ifstream ipcFile;
    Exception::open(ipcFile, Options::instance().ipcFile());

    size_t shmemID;
    size_t pid;

    if (not (ipcFile >> shmemID >> pid))
        throw Exception() << "Can't read the Shared Memory ID from " <<
                                Options::instance().ipcFile();

    imsg << "shared memory ID: " << shmemID << endl;

    d_shmem = SharedMemory(shmemID);
    return pid;
}
