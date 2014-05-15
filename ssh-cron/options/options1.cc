#include "options.ih"

Options::Options()
:
    d_arg(ArgConfig::instance())
{
    // --help and --version already handled by versionHelp

    d_list = d_arg.option('l');

    bool noDaemon = d_arg.option(0, "no-daemon");
    d_daemon = not noDaemon;

    d_reload = d_arg.option('r');

    d_terminate = d_arg.option('t')    

    loadConfigFile();

    if (not d_arg.option(&d_PIDfile, 'p'))
        d_PIDfile = s_defaultPIDfile;

    d_stdout = d_arg.option('s');

    if (not d_arg.option(&d_agent, "agent"))
        d_agent = s_defaultAgent;

    d_log = d_arg.option(&d_logName, 'L');

    d_verbose = d_arg.option(0, "verbose");

    setSyslogParams();




    if (
        d_arg.nArgs() == 0 && d_arg.nOptions() == 0 && 
        d_arg.nLongOptions() == 0
    )
    {
        usage(d_arg.basename());
        throw 0;
    }

    setSignalMembers();
    setBoolMembers();

    setSyslogParams();

    if (not d_verbose)
        imsg.off();
}       


