#include "cron.ih"

void Cron::stop(size_t signal)
{
    d_run = false;
    kill(pid(), SIGTERM);
}
