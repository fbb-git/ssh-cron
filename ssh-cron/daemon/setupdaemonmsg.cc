#include "daemon.ih"

void Daemon::setupDaemonMsg()
{
    if (not d_options.syslog())
    {
        imsg.off();
        wmsg.off();

        return;
    }
                                // verbose msg via syslog
    if (d_options.verbose())
        imsg.reset(*d_syslog);
    else
        imsg.off();

    wmsg.reset(*d_syslog);      // warnings via syslog
}
