#include "crondata.ih"

void CronData::setAll(size_t step) 
{
    if (step == 1)
        d_all = true;
    else
        addRange(d_entryBegin, d_entryEnd - 1, step);
}

