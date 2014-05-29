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
    "               option descriptions starting with (C) may also be\n"
    "               specified in the config file (see option --config)):\n"
    "      --agent agent    - (C) absolute path to the agent program "
                                                                "providing\n"

    "                         the ssh-keys\n"
    "                         (default `" << s_defaultAgent << "')\n"
    "      --config (-c) path - config file containing long option "
                                                            "specifications\n"
    "                         (default `$HOME/" <<
                                    s_defaultConfigFile << ")`\n"
    "      --help (-h)      - provide this help\n"
    "      --ipc-file (-i) path - (C) `path' is the path name of the file\n"
    "                         containing the info used for IPC\n"
    "                         (default `" << s_defaultIPCfile << "')\n"
    "      --list (-l)      - list the currently defined cron-commands\n"
    "                         (the `crontab' file is only used to specify "
                                                            "options)\n"
    "      --log (-L) path  - (C) log messages are appended to `path'. If "
                                                                    "path\n"
    "                         does not exist, it is created first\n"
    "      --mailer (-m) command - (C) `command' is the command mailing the\n"
    "                         output of executed commands (default\n"
    "                         `" << s_defaultMailer << "'\n"
    "      --no-daemon      - do not run as a daemon\n"
    "      --reload (-r)    - reload a running " << progname << " program\n"
    "                         with the specifications in the crontab-file\n"
    "      --syslog         - (C) write syslog messages\n"
    "      --syslog-facility fac  - (C) fac: syslog facility to use\n"
    "                         (default `" << s_defaultSyslogFacility << "')\n"
    "      --syslog-priority pri  - (C) pri: syslog priority to use\n"
    "                         (default `" << s_defaultSyslogPriority << "')\n"
    "      --syslog-tag id  - (C) id: identifier prefixed to syslog "
                                                                "messages\n"
    "                         (default `" << s_defaultSyslogIdent << "')\n"
    "      --terminate (-t) - terminate a running " << progname << 
                                                                " program\n"
    "                         (the `crontab' file is only used to specify "
                                                            "options)\n"
    "      --verbose        - (C) logs additional information. Implies "
                                                            "--syslog\n"
    "      --version (-v)   - show version information and terminate\n"
    "\n"
    "   crontab     - crontab-like file specifying crontab commands, and\n"
    "                 (optional) environment variable definitions and/or "
                                                                    "long\n"
    "                 options. If the ipc-file exists, commands defined in\n"
    "                 `crontab' replace the commands defined for the "
                                                                "currently\n"
    "                 running " << progname << "\n" 
    "\n";
}


