#include "daemon.ih"

void Daemon::terminate() const
{
    basename() << "--terminate" << endl;

    IPCInfo info = getIPCInfo();

    idmsg() << "terminating process " << info.pid << endl;
    kill(info.pid, SIGTERM);
}




