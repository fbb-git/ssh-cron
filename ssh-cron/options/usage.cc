//                     usage.cc

#include "options.ih"

void Options::usage(std::string const &progname)
{
    cout << "\n" <<
    progname << " by " << author << "\n" <<
    progname << " V" << version << " " << years << "\n"
    "\n"
    "Usage: " << progname << " [options] [crontab]\n"
    "Where:\n"
    "   [options] - optional arguments (short options between parentheses,\n"
    "               option descriptions starting with (C) can only be used\n"
    "               on the command-line and are ignored when specified in "
                                                                    "the\n"
    "               configuration file (see also option --config):\n"
    "      --agent agent    - absolute path to the agent program providing\n"
    "                         the ssh-keys\n"
    "                         (default `" << s_defaultAgent << "')\n"
    "      --config (-c) path - (C) config file containing long option "
                                                            "specifications\n"
    "                         (default `$HOME/" <<
                                    s_defaultConfigFile << ")`\n"
    "      --forced (-f)    - (C) When restarting " << progname << 
                                                            " an existing\n"
    "                         (leftover) ipc-file is removed\n"
    "      --help (-h)      - (C) provide this help\n"
    "      --ipc-file (-i) path - `path' is the path name of the file\n"
    "                         containing the info used for IPC\n"
    "                         (default `$HOME/" << s_defaultIPCfile << "')\n"
    "      --list (-l)      - list the currently defined cron-commands\n"
    "                         (the `crontab' file is only used to specify "
                                                            "options)\n"
    "      --log (-L) path  - log messages are appended to `path'. If "
                                                                    "path\n"
    "                         does not exist, it is created first\n"
    "      --mailer (-m) command - `command' is the command mailing the\n"
    "                         output of executed commands (default\n"
    "                         `" << s_defaultMailer << "'\n"
    "      --no-daemon      - (C) do not run as a daemon\n"
    "      --reload (-r)    - (C) reload a running " << progname << 
                                                                " daemon\n"
    "                         with the specifications in the crontab-file\n"
    "      --stdout (-s)    - (C) logged messages are also written to "
                                                                    "stdout\n"
    "                         (only in combination with --no-daemon)\n"

    "      --syslog         - write syslog messages\n"
    "      --syslog-facility fac  - fac: syslog facility to use\n"
    "                         (default `" << s_defaultSyslogFacility << "')\n"
    "      --syslog-priority pri  - pri: syslog priority to use\n"
    "                         (default `" << s_defaultSyslogPriority << "')\n"
    "      --syslog-tag id  - id: identifier prefixed to syslog "
                                                                "messages\n"
    "                         (default `" << s_defaultSyslogIdent << "')\n"
    "      --terminate (-t) - (C) terminate a running " << progname << 
                                                                " program\n"
    "                         (the `crontab' file is only used to specify "
                                                            "options)\n"
    "      --verbose        - logs additional information. Implies "
                                                            "--syslog\n"
    "      --version (-v)   - (C) show version information and terminate\n"
    "\n"
    "   crontab     - crontab-like file specifying crontab commands and\n"
    "                 (optional) environment variable definitions\n"
    "\n";
}


