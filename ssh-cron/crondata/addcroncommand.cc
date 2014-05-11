#include "crondata.ih"

void CronData::addCronCommand()
{
    d_next.setNsettings(d_environment.size());
    d_cronEntries.push_back(d_next);

    imsg << "Cron " << d_cronEntries.size() << ": " << d_next << endl;
}
