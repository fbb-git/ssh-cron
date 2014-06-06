#include "daemon.ih"

Daemon::IPCInfo Daemon::getIPCInfo() const
{
    ifstream ipcFile;
    Exception::open(ipcFile, Options::instance().ipcFile());

    IPCInfo info;

    if (not (ipcFile >> info.shmemID >> info.pid))
        fmsg << "corrupted " << Options::instance().ipcFile() << endl;

    idmsg() << "IPC info: shared memory ID: " << info.shmemID << 
            ", daemon PID: " << info.pid << endl;

    return info;
}
