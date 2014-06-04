#include "daemon.ih"

void Daemon::enterThread(Daemon *obj)
{
    Tty tty;
    tty.echo(Tty::OFF);
    cin.ignore(numeric_limits<int>::max(), '\n');

    kill(getpid(), SIGTERM);
}
