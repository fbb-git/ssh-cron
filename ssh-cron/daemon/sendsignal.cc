#include "daemon.ih"

void Daemon::sendSignal()
{
    pid_t pid = cronPid();

    if (d_options.terminate())
        kill(pid, SIGTERM);
//    else
//        list(pid, SIGHUP);
}
