#include "crondata.ih"

set<size_t> CronData::assign()
{
    set<size_t> dest;

    if (d_wip.size())
    {
        size_t last = *d_wip.rbegin();
        if (last >= d_entryEnd)
        {
            outOfRange(last);
            return dest;
        }
    }

    if (emsg.count() == 0)
    {
        if (!d_all)
            dest = d_wip;
        else
        {
            dest.insert(s_values, s_values + d_entryEnd);
            dest.insert(dest.end(), CronEntry::STAR);
        }
    }

    d_wip.clear();
    d_all = false;

    return dest;
}
