#include "cron.ih"

Cron::Cron(ostream &stdMsg, CronData const &cronData)
:
    d_stdMsg(stdMsg),
    d_cronData(cronData)
{}
