#include "cron.ih"

void Cron::signalHandler(size_t signum)
{
    switch (signum)
    {
        case SIGTERM:
        throw 0;

        case SIGHUP:
            d_action = LIST;
        break;

        case SIGUSR1:
            d_action = RELOAD;
        break;
    }
}
