//                     usage.cc

#include "main.ih"

void usage(std::string const &progname)
{
    cout << "\n" <<
    progname << " by " << Icmbuild::author << "\n" <<
    progname << " V" << Icmbuild::version << " " << Icmbuild::years << "\n"
    "\n"
    "Usage: " << progname << " [options] [crontab]\n"
    "Where:\n"
    "   [options] - optional arguments (short options between parentheses,\n"
    "               option descriptions starting with (C) may also be
    "               specified in the config file (see option --config)):\n"
    "      --agent agent    - (C) absolute path to the agent program "
                                                                "providing\n"

    "                         the ssh-keys\n"
    "                         (default `" << 
                                        Options::defaultAgent() << "')\n"
    "      --config (-c) path - config file containing long option "
                                                            "specifications\n"
    "                         (default `$HOME/" <<
                                    Options::defaultConfigFile() << ")`\n"
    "      --help (-h)      - provide this help\n"
    "      --list (-l)      - list the currently defined cron-commands\n"
    "                         (the `crontab' file is only used to specify "
                                                            "options)\n"
    "      --log (-L) path  - (C) log messages are appended to `path'. If "
                                                                    "path\n"
    "                         does not exist, it is created first\n"
    "      --no-daemon      - do not run as a daemon\n"
    "      --no-syslog      - (C) do not write syslog messages\n"
    "      --pid-file (-p) path - (C) `path' is the path name of the file\n"
    "                         containing the daemon's PID\n"
    "                         (default `" <<
                                        Options::defaultPIDfile() << "')\n"
    "      --reload (-r)    - reload a running " << progname << " program\n"
    "                         with the specifications in the crontab-file\n"
    "      --stdout (-s)    - (C) write syslog-equivalent messages to the std "
                                                                "output\n"
    "                         (implied by --verbose; only used with " 
                                                            "--no-daemon)\n"
    "      --syslog-facility fac  - (C) fac: syslog facility to use\n"
    "                         (default `" << 
                                    Options::defaultSyslogFacility() << "')\n"
    "      --syslog-priority pri  - (C) pri: syslog priority to use\n"
    "                         (default `" << 
                                    Options::defaultSyslogPriority() << "')\n"
    "      --syslog-tag id  - (C) id: identifier prefixed to syslog "
                                                                "messages\n"
    "                         (default `" << 
                                    Options::defaultSyslogIdent() << "')\n"
    "      --terminate (-t) - terminate a running " << progname << 
                                                                " program\n"
    "                         (the `crontab' file is only used to specify "
                                                            "options)\n"
    "      --verbose        - (C) write additional information:\n"
    "                            with --no-daemon: to stdout;\n"
    "                            with daemons and --no-syslog not "
                                                                "specified:\n"
    "                                               to the syslog daemon\n"
    "      --version (-v)   - show version information and terminate\n"
    "\n"
    "   crontab     - crontab-like file specifying crontab commands, and\n"
    "                 (optional) environment variable definitions and/or "
                                                                    "long\n"
    "                 options. If the pid-file exists, commands defined in\n"
    "                 `crontab' replace the commands defined for the "
                                                                "currently\n"
    "                 running " << progname << "\n" 
    "\n";
}


