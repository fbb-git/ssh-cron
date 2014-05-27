#include "daemon.ih"

pid_t Daemon::cronPid() const
{
    ifstream in;
    string const &ipcFile = d_options.ipcFile();
    Exception::open(in, ipcFile);
    pid_t pid;

    if (not (in >> pid))
        fmsg << "can't read ssh-cron daemon's ipc from " << ipcFile << endl;

    return pid;
}
