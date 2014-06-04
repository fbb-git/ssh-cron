#include "daemon.ih"

void Daemon::ipc()
{
    switch (d_options.ipcFunction())
    {
        case TERMINATE:
            terminate();
        break;

        case LIST:
            listRequest();
        break;

        case RELOAD:
            reload();
        break;

        default:
        break;
    }
}

