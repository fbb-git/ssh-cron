#include "cron.ih"

void Cron::stop(size_t signal)
{
    d_run = false;
    d_interrupted = signal == SIGINT;
}
