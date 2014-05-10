#include "crondata.ih"

void CronData::setMinutes() 
{
    if (d_wip.size())
    {
        size_t last = *d_wip.rbegin();
        if (last >= 60)
        {
            outOfRange(last);
            return;
        }
    }

    if (emsg.count() != 0)
        return;

    if (!d_all)
        d_next.minutes = d_wip;
    else
        d_next.minutes.insert(s_values, s_values + 60);

    d_entryName = "hours";
    d_entryEnd = 24;
}
