#include "cron.ih"

Cron::Cron(CronData &cronData)
:
    d_options(Options::instance()),
    d_cronData(cronData)
{}
