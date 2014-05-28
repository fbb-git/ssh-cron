#include "cron.ih"

Cron::Cron(CronData const &cronData)
:
    d_options(Options::instance()),
    d_cronData(cronData)
{}
