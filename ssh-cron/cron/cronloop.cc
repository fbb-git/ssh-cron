#include "cron.ih"

void Cron::cronLoop()
{
    while (true)
    {
        size_t seconds = time(0) % 60;
        
        if (seconds != 0)
        {
            imsg << "Sleeping for " << (60 - seconds) << " seconds" << endl;
            sleep(60 - seconds);    // ends at a sighup signal
        }

        runCronJobs();

        if (time(0) % 60 == 0)
            sleep(1);               // ends at a sighup signal

        switch (d_action)
        {
            case LIST:
//                list();
            break;

            case RELOAD:
//                reload();
            break;

            default:
            break;
        }
        d_action = LOOP;
    }
}

