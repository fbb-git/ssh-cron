#include "options.ih"

Options::Options()
:
    d_arg(ArgConfig::instance())
{
    if (
        d_arg.nArgs() == 0 && d_arg.nOptions() == 0 && 
        d_arg.nLongOptions() == 0
    )
    {
        usage(d_arg.basename());
        throw true;
    }

    d_arg.open(d_arg[0]);           // read the arg config file, which is also
                                    // the cron-file

    if (not d_arg.option(&d_PIDfile, 'p'))
        d_PIDfile = s_defaultPIDfile;

    setSyslogParams();
    setBoolMembers();

    if (not d_verbose)
        imsg.off();
}       
