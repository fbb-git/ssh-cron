#include "crondata.ih"

void CronData::setMinutes() 
{
    d_next.setMinutes(assign());

    d_entryName = "hours";
    d_entryEnd = 24;
}
