#include "cron.ih"

void Cron::runCronJobs()            // called from cronloop
{
    DateTime now(DateTime::LOCALTIME);

    for (CronEntry const &entry: d_cronData.cronEntries())
    {
        if (call(now, entry))
        {
            if (not d_run)
                throw EndOfRun();   // caught by cronloop

            execute(entry);
        }
    }
}
