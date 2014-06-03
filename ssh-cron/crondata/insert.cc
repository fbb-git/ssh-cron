#include "crondata.ih"

ostream &CronData::insert(ostream &out) const
{
    for (auto &spec: d_environment)
        out << spec << '\n';

    for (auto &entry: d_cronEntries)
        entry.insert(out) << '\n';

    return out << flush;
}
