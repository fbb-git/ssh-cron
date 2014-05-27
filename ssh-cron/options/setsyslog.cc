#include "options.ih"

void Options::setSyslog()
{
    if (not d_arg.option(0, "syslog"))
        return;

    d_syslog.reset(
                new SyslogStream(
                    syslogTag(), syslogPriority(), syslogFacility()
                )
            );

    d_multiStreambuf.insert(*d_syslog);
}
