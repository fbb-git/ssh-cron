#include "crondata.ih"

void CronData::addNr(size_t nr)
{
    if (d_entryBegin <= nr && nr < d_entryEnd)
        d_wip.insert(nr);
    else
        outOfRange(nr);
}
