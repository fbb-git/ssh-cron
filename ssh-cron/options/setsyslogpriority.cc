#include "options.ih"

void Options::setSyslogPriority()
{
    d_syslogPriority = s_syslogPriorities.find(s_defaultSyslogPriority);

    string option;
    if (not d_arg.option(&option, "syslog-priority"))
    {
        LinearMap<std::string, FBB::Priority>::const_iterator 
            priority = s_syslogPriorities.find(option);

        if (priority != s_syslogPriorities.end())
            d_syslogPriority = priority;
        else
            d_syslogPriorityError = option;
    }            
}
