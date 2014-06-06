#include "cron.ih"

ostream &Cron::idmsg() const
{
    return imsg << "scheduler: ";
}
