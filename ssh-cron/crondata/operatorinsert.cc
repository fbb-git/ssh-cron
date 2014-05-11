#include "crondata.ih"

ostream &operator<<(ostream &out, CronData::Entry const &entry)
{
    if (entry.nSettings > 0)
        out << "using " << entry.nSettings << " env. settings:\n";

    CronData::showSet(out, entry.minutes);
    out << "    ";

    CronData::showSet(out, entry.hours);
    out << "    ";

    CronData::showSet(out, entry.dayOfMonth);
    out << "    ";

    CronData::showSet(out, entry.monthOfYear);
    out << "    ";

    CronData::showSet(out, entry.dayOfWeek);
    return out << "    " << entry.command;
}

