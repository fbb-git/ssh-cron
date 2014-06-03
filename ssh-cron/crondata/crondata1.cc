#include "crondata.ih"

CronData::CronData()
:
    d_entryName("minutes"),
    d_info(not Options::instance().reload())
{}
