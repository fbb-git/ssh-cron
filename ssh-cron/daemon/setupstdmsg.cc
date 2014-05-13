#include "daemon.ih"

void Daemon::setupStdMsg()
{
    if (d_options.stdout())             // if --stdout, then messages also go
        d_multiStreambuf.insert(cout);  // to stdout

    if (d_options.syslog())             // always set up syslog
    {
        d_syslog.reset(
            new SyslogStream(
                d_options.syslogTag().c_str(), d_options.syslogPriority(), 
                d_options.syslogFacility()
            )
        );

        d_multiStreambuf.insert(*d_syslog);
    }

    checkSyslogParam("facility", d_options.facility(), 
                                 d_options.syslogFacilityError());

    checkSyslogParam("priority", d_options.priority(), 
                                 d_options.syslogPriorityError());
}
