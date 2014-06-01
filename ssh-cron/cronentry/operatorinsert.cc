#include "cronentry.ih"

ostream &operator<<(ostream &out, CronEntry const &entry)
{
    auto begin = entry.d_environment->begin() + entry.d_begin;
    auto end   = entry.d_environment->begin() + entry.d_end;

    bool envVars = begin != end;

    if (envVars && entry.d_begin > 0)   // separate previous command list by
        out.put('\n');                  // empty line

    for ( ; begin != end; ++begin)
        out << "Envvar: " << *begin << '\n';

    if (envVars)                // separate env. vars from command(s)
        out.put('\n');

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

