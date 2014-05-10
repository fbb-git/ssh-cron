#include "crondata.ih"

void CronData::process()
{
    d_entryName = "minutes";
    d_entryEnd = 60;
    d_next = Entry();
    emsg.setCount(0);
}
