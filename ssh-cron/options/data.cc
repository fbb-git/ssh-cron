#include "options.ih"

Options *Options::s_options = 0;

char const Options::s_defaultAgent[]        = "/usr/bin/ssh-agent /bin/bash";
char const Options::s_defaultIPCfile[]      = ".ssh-cron.ipc";
char const Options::s_defaultConfigFile[]   = ".ssh-cron";
char const Options::s_defaultMailer[]       = 
            "/usr/bin/mail -s \"Ssh-cron $*\" $USER@localhost";

char const Options::s_defaultSyslogIdent[]      = "SSH-CRON";
Facility Options::s_defaultSyslogFacility   = Facility::DAEMON;
Priority Options::s_defaultSyslogPriority   = Priority::NOTICE;

LinearMap<string, Facility> const Options::s_syslogFacilities = 
    {
        {"DAEMON", Facility::DAEMON}, 
        {"LOCAL0", Facility::LOCAL0},
        {"LOCAL1", Facility::LOCAL1},
        {"LOCAL2", Facility::LOCAL2},
        {"LOCAL3", Facility::LOCAL3},
        {"LOCAL4", Facility::LOCAL4},
        {"LOCAL5", Facility::LOCAL5},
        {"LOCAL6", Facility::LOCAL6},
        {"LOCAL7", Facility::LOCAL7},
        {"USER",   Facility::USER}
    };

LinearMap<string, Priority> const Options::s_syslogPriorities = 
    {
       {"EMERG",    Priority::EMERG},
       {"ALERT",    Priority::ALERT},
       {"CRIT",     Priority::CRIT},
       {"ERR",      Priority::ERR},
       {"WARNING",  Priority::WARNING},
       {"NOTICE",   Priority::NOTICE},
       {"INFO",     Priority::INFO},
       {"DEBUG",    Priority::DEBUG}
    };





