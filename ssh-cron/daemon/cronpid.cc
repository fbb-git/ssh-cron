#include "daemon.ih"

pid_t Daemon::cronPid() const
{
    ifstream in;
    string const &pidFile = d_options.pidFile();
    Exception::open(in, pidFile);
    pid_t pid;

    if (not (in >> pid))
        fmsg << "can't read ssh-cron daemon's pid from " << pidFile << endl;

    return pid;
}
