#include "crondata.ih"

void CronData::setMonthOfYear()
{
    d_next.setMonthOfYear(assign(s_month));

    d_entryName = "day of week";
    d_entryBegin = 0;
    d_entryEnd = 7;
}
