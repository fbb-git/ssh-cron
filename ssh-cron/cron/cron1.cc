#include "cron.ih"

Cron::Cron(ofstream &stdMsg, CronData const &cronData)
:
    d_stdMsg(stdMsg),
    d_cronData(cronData)
{}
