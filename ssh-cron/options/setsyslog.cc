#include "options.ih"

bool Options::setSyslog()
{
    if (not d_arg.option(0, "syslog"))
        return false;

    d_syslog.reset(
                new SyslogStream(
                    syslogTag(), syslogPriority(), syslogFacility()
                )
            );

    d_multiStreambuf.insert(*d_syslog);
    return true;
}
