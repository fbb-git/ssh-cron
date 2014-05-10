#include "crondata.ih"

void CronData::addRange(size_t first, size_t last, size_t step)
{
    if (last > 60)
        outOfRange(last);

    if (step == 0)
        emsg << "Line " << d_lineNr << ": step size must be >= 1" << out;
        
    if (first > last)
    {
        emsg << "Line " << d_lineNr << ": invalid range " << 
                 first << '-' << last << out;
    }
        
    if (g_errors)
        return;

    for (++first, ++last; first <= last; first += step)
        d_wip.insert(first);
}
