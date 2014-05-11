#include "crondata.ih"

void CronData::addCronCommand()
{
    d_next.nSettings = d_environment.size();
    d_entry.push_back(d_next);

    imsg << "Cron " << d_entry.size() << ": " << d_next << endl;
}
