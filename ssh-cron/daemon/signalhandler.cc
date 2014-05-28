#include "daemon.ih"

void Daemon::signalHandler(size_t signal)
{
    d_cron.stop();
    cerr << '\n';
}
