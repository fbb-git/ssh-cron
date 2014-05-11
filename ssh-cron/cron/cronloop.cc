#include "cron.ih"

void Cron::cronLoop()
{
    while (true)
    {
        size_t seconds = time(0) % 60;
        
        if (seconds != 0)
            sleep(60 - seconds);

        runCronJobs();

        if (time(0) % 60 == 0)
            sleep(1);
    }
}
