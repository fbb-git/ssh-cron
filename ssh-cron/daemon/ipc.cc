#include "daemon.ih"

void Daemon::ipc()
{
    if (d_options.terminate())
        terminate();
}

