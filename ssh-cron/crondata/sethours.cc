#include "crondata.ih"

void CronData::setHours()
{
    d_next.setHours(assign());

    d_entryName = "day of month";
    d_entryBegin = 1;
    d_entryEnd = 32;
}
