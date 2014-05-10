#include "crondata.ih"

void CronData::addRange(size_t first, size_t last, size_t step)
{
    if (last >= d_entryEnd)
        invalidRange(first, last);

    if (step == 0)
        emsg << "Line " << d_lineNr << ": step size must be >= 1" << endl;
        
    if (first > last)
    {
        emsg << "Line " << d_lineNr << ": invalid range " << 
                 first << '-' << last << endl;
    }
        
    if (emsg.count() != 0)
        return;

    for (++first, ++last; first <= last; first += step)
        d_wip.insert(first);
}
