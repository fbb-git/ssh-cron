#include "crondata.ih"

void CronData::outOfRange(size_t nr) const
{
    emsg << "Line " << d_lineNr << ": nr " << nr << " out of range" << out; 
}
