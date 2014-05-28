#include "cron.ih"

Cron::Cron(CronData const &cronData)
:
    d_options(Options::instance()),
    d_cronData(cronData)
{
    imsg << "cron(): d_run = " << d_run << '\n';
}
