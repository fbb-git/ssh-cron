#include "options.ih"

Options::Options()
:
    d_arg(ArgConfig::instance()),
    d_msg(&d_multiStreambuf)
{
    // --help and --version already handled by versionHelp

    d_noDaemon = d_arg.option(0, "no-daemon");
    d_list = d_arg.option('l');
    d_reload = d_arg.option('r');
    d_terminate = d_arg.option('t');

    checkAction();

    loadConfigFile();

    if (not d_arg.option(&d_agent, "agent"))
        d_agent = s_defaultAgent;

    if (not d_arg.option(&d_IPCfile, 'i'))
        d_IPCfile = s_defaultIPCfile;

    string logName;
    if (d_arg.option(&logName, 'L'))
    {
        d_log.open(logName);
        if (not d_log)
            fmsg << "could not open " << logName << endl;

        d_log.setLevel(0);              // to be removed with bobcat > 3.22.01
        d_multiStreambuf.insert(d_log);
    }

    setSyslog();


    if d_verbose = d_arg.option(0, "verbose");

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


    if (not d_verbose)
        imsg.off();

/////////////////////
    setupStdMsg();

    if (d_options.daemon())
        setupDaemonMsg();
    else
        setupNonDaemonMsg();

}       








