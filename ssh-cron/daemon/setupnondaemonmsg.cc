#include "daemon.ih"

void Daemon::setupNonDaemonMsg()
{
    if (not d_options.verbose())
        imsg.off();
}
