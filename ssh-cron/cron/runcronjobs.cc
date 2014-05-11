#include "cron.ih"

void Cron::runCronJobs()
{
    DateTime now(DateTime::LOCALTIME);

    for (CronEntry const &entry: d_cronData.cronEntries())
    {
        if (call(now, entry))
            execute(entry);
    }
}
