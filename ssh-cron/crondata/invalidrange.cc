#include "crondata.ih"

void CronData::invalidRange(size_t first, size_t last) const
{
    emsg << "Line " << d_lineNr << " (" << d_entryName << 
                        "): invalid range " << first << '-' << last << endl;
}
