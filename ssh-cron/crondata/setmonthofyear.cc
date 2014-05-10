#include "crondata.ih"

void CronData::setMonthOfYear()
{
    assign(d_next.dayOfMonth, s_month);

    d_entryName = "day of week";
    d_entryEnd = 7;
}
