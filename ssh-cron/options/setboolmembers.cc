#include "options.ih"

void Options::setBoolMembers()
{
    // d_useSyslog is set in `setSyslogParams'

    d_daemon = not d_arg.option(0, "no-daemon");
    d_verbose = d_arg.option(0, "verbose");
    d_stdout = d_verbose || d_arg.option('s');
//    d_warnings = d_arg.option('w');
}
