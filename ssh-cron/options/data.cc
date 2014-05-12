#include "options.ih"

Options *Options::s_options = 0;

char const Options::s_defaultSyslogIdent[]      = "SSH-CRON";
char const Options::s_defaultSyslogFacility[]   = "DAEMON";
char const Options::s_defaultSyslogPriority[]   = "NOTICE";

char const Options::s_defaultPIDfile[]          = "/run/ssh-cron.pid";

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





