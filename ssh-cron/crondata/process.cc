#include "crondata.ih"

void CronData::process()
{
    if (emsg.count() == 0)
        addCronCommand();

    d_entryName = "minutes";
    d_entryEnd = 60;
    d_next = CronEntry();
    emsg.setCount(0);
}
