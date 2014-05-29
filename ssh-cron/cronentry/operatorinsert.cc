#include "cronentry.ih"

ostream &operator<<(ostream &out, CronEntry const &entry)
{
    for 
    (
        auto begin = entry.d_environment->begin() + entry.d_begin,
             end   = entry.d_environment->begin() + entry.d_end;

            begin != end;
                ++begin
    )
        out << *begin << '\n';

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

