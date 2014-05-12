#include "options.ih"

void Options::setSyslogParams()
{
    d_useSyslog = not d_arg.option(0, "no-syslog");

    if (d_useSyslog)
    {
        if (not d_arg.option(&d_syslogTag, "syslog-tag"))
            d_syslogTag = s_defaultSyslogIdent;
    
        setSyslogFacility();
        setSyslogPriority();
    }
}
