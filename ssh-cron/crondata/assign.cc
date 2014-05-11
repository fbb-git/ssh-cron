#include "crondata.ih"

void CronData::assign(set<size_t> &dest)
{
    if (d_wip.size())
    {
        size_t last = *d_wip.rbegin();
        if (last >= d_entryEnd)
        {
            outOfRange(last);
            return;
        }
    }

    if (emsg.count() == 0)
    {
        if (!d_all)
            dest = d_wip;
        else
        {
            dest.insert(s_values, s_values + d_entryEnd);
            dest.insert(dest.end(), STAR);
        }
    }

    d_wip.clear();
    d_all = false;
}
