#include "cronentry.ih"

ostream &CronEntry::insert(ostream &out) const
{
    showSet(out, d_minutes);
    out << "    ";

    showSet(out, d_hours);
    out << "    ";

    showSet(out, d_dayOfMonth);
    out << "    ";

    showSet(out, d_monthOfYear);
    out << "    ";

    showSet(out, d_dayOfWeek);
    return out << "    " << d_command;
}
