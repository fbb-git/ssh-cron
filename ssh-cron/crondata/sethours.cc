#include "crondata.ih"

void CronData::setHours()
{
    assign(d_next.hours);

    d_entryName = "day of month";
    d_entryBegin = 1;
    d_entryEnd = 32;
}
