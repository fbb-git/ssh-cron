#include "crondata.ih"

void CronData::addNr(size_t nr)
{
    if (d_entryBegin <= nr && nr <= d_entryEnd)     // <=, so allowEnd is
        d_wip.insert(nr);                           // handled 
    else
        outOfRange(nr);
}
