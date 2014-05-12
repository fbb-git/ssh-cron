#include "daemon.ih"

void Daemon::runParentProcess()
{
    cin.ignore(numeric_limits<int>::max(), '\n');
    kill(pid(), SIGTERM);
}

