#include "cron.ih"

Cron::Cron(ofstream &stdMsg, CronData const &cronData)
:
    d_cronData(cronData),
    d_sendCommands(ArgConfig::instance().option(0, "verbose") == 0),
    d_log("/tmp/log")
{}
