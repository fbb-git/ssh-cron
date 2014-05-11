#include "crondata.ih"

void CronData::assign(set<size_t> &dest,  char const *const *names,
                    bool allowEnd)
{
    size_t size = d_entryEnd - d_entryBegin;

    for (string const &name: d_names)
    {
        char const *const *ptr = find(names, names + size, name);
        if (ptr != names + size)
            d_wip.insert(d_entryBegin + ptr - names);
        else
            emsg <<  "Line " << d_lineNr << " (" << d_entryName << "): `" << 
                name << "' not supported" << endl;
    }

    d_names.clear();
     
    if (allowEnd && d_wip.find(d_entryEnd) != d_wip.end())
    {
        d_wip.erase(d_entryEnd);
        d_wip.insert(0);
    }

    assign(dest);
}

