#include "daemon.ih"

void Daemon::setupStdMsg()
{
    if (d_options.stdout())             // if --stdout, then messages also go
        d_multiStreambuf.insert(cout);  // to stdout

    if (d_options.log())
    {
        d_log.open(d_options.logName());
        if (not d_log)
            fmsg << "could not open " << d_options.logName() << endl;

        d_log.setLevel(0);              // to be removed with bobcat > 3.22.01

        d_multiStreambuf.insert(d_log);
    }

    if (d_options.syslog())         // do we need syslog?
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



