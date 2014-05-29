#include "daemon.ih"

void Daemon::ipc()
{
    switch (d_options.ipcFunction())
    {
        case TERMINATE:
            terminate();
        break;

        case LIST:
            list();
        break;

        default:
        break;
    }
}

