#include "crondata.ih"

void CronData::setDayOfWeek()
{
    d_next.setDayOfWeek(assign(s_day, true));
}
