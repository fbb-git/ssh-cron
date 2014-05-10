#include "crondata.ih"

void CronData::outOfRange(size_t nr) const
{
    emsg << "Line " << d_lineNr << " (" << d_entryName << "): " << nr << 
            " out of range" << endl;
}
