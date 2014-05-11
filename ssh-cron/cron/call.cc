#include "cron.ih"

bool Cron::call(DateTime const &now, CronEntry const &entry)
{
    return 
        specified(now.minutes(), entry.minutes())
        &&
        specified(now.hours(), entry.hours())
        &&
        specified(now.month() + 1, entry.monthOfYear())
        &&
        (
            specified(now.monthDayNr(), entry.dayOfMonth())
            ||
            specified(now.weekday(), entry.dayOfWeek())
        );
}
