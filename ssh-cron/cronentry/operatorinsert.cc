#include "cronentry.ih"

ostream &operator<<(ostream &out, CronEntry const &entry)
{
    if (entry.d_nSettings > 0)
        out << "using " << entry.d_nSettings << " env. settings:\n";

    CronEntry::showSet(out, entry.d_minutes);
    out << "    ";

    CronEntry::showSet(out, entry.d_hours);
    out << "    ";

    CronEntry::showSet(out, entry.d_dayOfMonth);
    out << "    ";

    CronEntry::showSet(out, entry.d_monthOfYear);
    out << "    ";

    CronEntry::showSet(out, entry.d_dayOfWeek);
    return out << "    " << entry.d_command;
}

