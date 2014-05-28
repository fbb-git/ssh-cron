#include "daemon.ih"

void Daemon::signalHandler(size_t signal)
{
    d_cron.stop(signal);
    cerr << '\n';
}
