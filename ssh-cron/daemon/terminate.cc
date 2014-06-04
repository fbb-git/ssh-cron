#include "daemon.ih"

void Daemon::terminate() const
{
    d_options.msg() << "--terminate issued" << endl;

    IPCInfo info = getIPCInfo();

    imsg << "terminating process " << info.pid << endl;
    kill(info.pid, SIGTERM);
}




