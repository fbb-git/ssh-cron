#include "cronentry.ih"

void CronEntry::showSet(ostream &out, set<size_t> const &nrSet)
{
    if (nrSet.find(STAR) != nrSet.end())
    {
        out << '*';
        return;
    }

    auto begin = nrSet.begin();
    out << *begin++;

    for (auto end = nrSet.end(); begin != end; ++begin)
        out << ',' << *begin;
}
