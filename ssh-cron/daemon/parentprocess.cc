#include "daemon.ih"

void Daemon::parentProcess()
{
    ofstream ipcFile;           // open the daemon's ipc-file:
    Exception::open(ipcFile, Options::instance().ipcFile());

            // see also cron/handlerequests and daemon/terminate
    ipcFile << d_shmem.id() << '\n' <<
               pid() << endl;
}















