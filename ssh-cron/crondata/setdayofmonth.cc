#include "crondata.ih"

void CronData::setDayOfMonth()
{
    d_next.setDayOfMonth(assign());

    d_entryName = "month of year";
    d_entryEnd = 13;
}
