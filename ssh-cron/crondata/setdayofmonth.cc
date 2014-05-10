#include "crondata.ih"

void CronData::setDayOfMonth()
{
    assign(d_next.dayOfMonth);

    d_entryName = "month of year";
    d_entryEnd = 13;
}
