#include "daemon.ih"

Daemon::IPCInfo Daemon::getIPCInfo()
{
    ifstream ipcFile;
    Exception::open(ipcFile, Options::instance().ipcFile());

    IPCInfo info;

    if (not (ipcFile >> info.shmemID >> info.pid))
        throw Exception() << "Can't read the Shared Memory ID from " <<
                                Options::instance().ipcFile();

    imsg << "shared memory ID: " << info.shmemID << endl;

    return info;
}
