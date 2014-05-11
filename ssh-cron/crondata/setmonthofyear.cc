#include "crondata.ih"

void CronData::setMonthOfYear()
{
    assign(d_next.monthOfYear, s_month);

    d_entryName = "day of week";
    d_entryBegin = 0;
    d_entryEnd = 7;
}
