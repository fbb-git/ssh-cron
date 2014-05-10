#include "crondata.ih"

void CronData::setDayOfWeek()
{
    assign(d_next.dayOfWeek, s_day, true);
}
