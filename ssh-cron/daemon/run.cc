#include "daemon.ih"

void Daemon::run()
{
    if (d_options.ipc())
        ipc();                          // handles commands to the daemon
    else if (d_options.foreground())
        foreground();                   // ssh-cron runs in the foreground
    else
        daemonize();                    // ssh-cron runs in the background
}
