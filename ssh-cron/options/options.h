#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <bobcat/syslogstream>
#include <bobcat/linearmap>
#include <bobcat/argconfig>

class Options
{
    FBB::ArgConfig &d_arg;

    std::string d_agent;
    std::string d_PIDfile;
    std::string d_syslogTag;
    std::string d_syslogPriorityError;
    std::string d_syslogFacilityError;
    std::string d_logName;

    FBB::LinearMap<std::string, FBB::Facility>::const_iterator 
                                                        d_syslogFacility;
    FBB::LinearMap<std::string, FBB::Priority>::const_iterator 
                                                        d_syslogPriority;
    bool d_daemon;
    bool d_verbose;
    bool d_stdout;
    bool d_useSyslog;
    bool d_terminate;
    bool d_list;
    bool d_log;

    static Options *s_options;

    static char const s_defaultAgent[];
    static char const s_defaultPIDfile[];
    static char const s_defaultSyslogIdent[];
    static char const s_defaultSyslogFacility[];
    static char const s_defaultSyslogPriority[];

    static FBB::LinearMap<std::string, FBB::Facility> const 
                                                       s_syslogFacilities;
    static FBB::LinearMap<std::string, FBB::Priority> const 
                                                       s_syslogPriorities;

    public:
        static Options &instance();

        Options(Options const &other) = delete;

        bool daemon() const;
        bool verbose() const;
        bool stdout() const;
        bool syslog() const;
        bool signal() const;
        bool terminate() const;
        bool list() const;
        bool log() const;

        std::string const &agent() const;
        std::string const &basename() const;
        std::string const &logName() const;
        std::string const &pidFile() const;
        std::string const &syslogTag() const;

        FBB::Priority syslogPriority() const;
        FBB::Facility syslogFacility() const;

        std::string const &priority() const;
        std::string const &facility() const;

        std::string syslogPriorityError() const;
        std::string syslogFacilityError() const;


        static char const *defaultAgent();
        static char const *defaultSyslogIdent();
        static char const *defaultSyslogFacility();
        static char const *defaultSyslogPriority();
        static char const *defaultPIDfile();

    private:
        Options();

        void setSignalMembers();
        void setSyslogParams();
        void setBoolMembers();
        void setSyslogFacility();
        void setSyslogPriority();
};

inline bool Options::daemon() const
{   
    return d_daemon;
}

inline bool Options::stdout() const
{   
    return d_stdout;
}

inline bool Options::syslog() const
{   
    return d_useSyslog;
}

inline bool Options::verbose() const
{   
    return d_verbose;
}

inline bool Options::signal() const
{   
    return d_terminate || d_list;
}

inline bool Options::terminate() const
{   
    return d_terminate;
}

inline bool Options::list() const
{   
    return d_list;
}

inline bool Options::log() const
{   
    return d_log;
}

inline std::string const &Options::agent() const
{   
    return d_agent;
}

inline std::string const &Options::basename() const
{   
    return d_arg.basename();
}

inline std::string const &Options::logName() const
{   
    return d_logName;
}

inline std::string const &Options::pidFile() const
{   
    return d_PIDfile;
}

inline std::string const &Options::syslogTag() const
{   
    return d_syslogTag;
}

inline FBB::Priority Options::syslogPriority() const
{   
    return d_syslogPriority->second;
}

inline std::string const &Options::priority() const
{   
    return d_syslogPriority->first;
}

inline std::string Options::syslogPriorityError() const
{   
    return d_syslogPriorityError;
}

inline FBB::Facility Options::syslogFacility() const
{   
    return d_syslogFacility->second;
}

inline std::string Options::syslogFacilityError() const
{   
    return d_syslogFacilityError;
}

inline std::string const &Options::facility() const
{   
    return d_syslogFacility->first;
}

inline char const *Options::defaultSyslogIdent() 
{
    return s_defaultSyslogIdent;
}

inline char const *Options::defaultAgent() 
{
    return s_defaultAgent;
}

inline char const *Options::defaultSyslogFacility() 
{
    return s_defaultSyslogFacility;
}

inline char const *Options::defaultSyslogPriority() 
{
    return s_defaultSyslogPriority;
}

inline char const *Options::defaultPIDfile() 
{
    return s_defaultPIDfile;
}
        
#endif

