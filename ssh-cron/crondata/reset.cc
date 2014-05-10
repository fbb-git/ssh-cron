#include "crondata.ih"

void CronData::reset(size_t lineNr) 
{
    d_lineNr = lineNr;
    d_wip.clear();
    d_names.clear();
    d_command.clear();
    d_all = false;
}

