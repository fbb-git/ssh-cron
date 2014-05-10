#include "crondata.ih"

void CronData::setMinutes() 
{
    assign(d_next.minutes);

    d_entryName = "hours";
    d_entryEnd = 24;
}
