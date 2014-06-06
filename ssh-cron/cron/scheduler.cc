#include "cron.ih"

ostream &Cron::scheduler() const
{
    return d_options.msg() << "scheduler: ";
}
