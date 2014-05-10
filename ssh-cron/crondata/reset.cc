#include "crondata.ih"

void CronData::reset(size_t lineNr) 
{
    d_lineNr = lineNr;
    d_entryBegin = 0;
    d_entryEnd = 60;
    d_entryName = "minutes";

    d_names.clear();

    d_all = false;
    d_wip.clear();
}

