#include "crondata.ih"

void CronData::addNr(size_t nr)
{
    if (nr < 60)
        d_wip.insert(nr);
    else 
        outOfRange(nr);
}

void CronData::setMinutes() {}
void CronData::setHours() {}
void CronData::setDayOfMonth() {}
void CronData::setMonthOfYear() {}
void CronData::setDayOfWeek() {}
