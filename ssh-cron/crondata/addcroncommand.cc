#include "crondata.ih"

void CronData::addCronCommand()
{
    d_next.setEnvironment(d_lastSize, d_environment.size(), &d_environment);
    d_lastSize = d_environment.size();

    d_cronEntries.push_back(d_next);

    if (d_info)
        imsg << Options::instance().basename() << ": cron " << 
                d_cronEntries.size() << '\n' << d_next << endl;
}
