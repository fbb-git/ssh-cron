#include "daemon.ih"

void Daemon::run()
{
    if (d_options.ipc())
        ipc();
    else if (d_options.foreground())
        foreground();
    else
        daemonize();     
}
