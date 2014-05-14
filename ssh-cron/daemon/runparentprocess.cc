#include "daemon.ih"

void Daemon::runParentProcess()
{
    cout << "Press `Enter' to end " << d_options.basename() << endl;

    noEcho();

    fork();

    cin.ignore(numeric_limits<int>::max(), '\n');

    imsg << "Terminating process " << pid() << endl;
    kill(pid(), SIGTERM);
}

