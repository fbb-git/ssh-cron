#include "crondata.ih"

void CronData::addNr(size_t nr)
{
    if (nr < d_entryEnd)
        d_wip.insert(nr);
    else
        outOfRange(nr);
}

void CronData::setHours() {}
void CronData::setDayOfMonth() {}
void CronData::setMonthOfYear() {}
void CronData::setDayOfWeek() {}
