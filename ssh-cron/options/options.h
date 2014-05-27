#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <memory>

#include <bobcat/argconfig>
#include <bobcat/linearmap>
#include <bobcat/log>
#include <bobcat/multistreambuf>
#include <bobcat/syslogstream>

namespace FBB
{
    class SyslogStream;
}

class Options
{
    FBB::ArgConfig &d_arg;

    std::unique_ptr<FBB::SyslogStream> d_syslog;
    FBB::Log d_log;

    FBB::MultiStreambuf d_multiStreambuf;
    std::ostream d_msg;                     // d_msg is used for messages
                                            // that should unconditionally be
                                            // shown. imsg is used when 
                                            // --verbose was requested,
                                            // wmsg is for warnings
                                            // emsg is for errors, used by 
                                            // the compiler.

    std::string d_agent;
    std::string d_IPCfile;
//    std::string d_syslogTag;
//    std::string d_syslogPriorityError;
//    std::string d_syslogFacilityError;
//    std::string d_logName;

    FBB::LinearMap<std::string, FBB::Facility>::const_iterator 
                                                        d_syslogFacility;
    FBB::LinearMap<std::string, FBB::Priority>::const_iterator 
                                                        d_syslogPriority;
    bool d_noDaemon;
    bool d_list;
    bool d_reload;
    bool d_terminate;
//    bool d_syslog;
//    bool d_verbose;

    static Options *s_options;

    static FBB::Facility    s_defaultSyslogFacility;
    static FBB::Priority    s_defaultSyslogPriority;
    static char const       s_defaultAgent[];
    static char const       s_defaultConfigFile[];
    static char const       s_defaultIPCfile[];
    static char const       s_defaultSyslogIdent[];

    static FBB::LinearMap<std::string, FBB::Facility> const 
                                                       s_syslogFacilities;
    static FBB::LinearMap<std::string, FBB::Priority> const 
                                                       s_syslogPriorities;

    public:
        static Options &instance();

        Options(Options const &other) = delete;

        bool daemon() const;
        bool terminate() const;
        bool list() const;

        std::string const &agent() const;
        std::string const &basename() const;
        std::string const &ipcFile() const;


    private:
        Options();

//        void setSyslogParams();
//        void setBoolMembers();
//        void setSyslogFacility();
//        void setSyslogPriority();
//        void checkAction() const;
        void loadConfigFile();

        std::string syslogTag() const;
        FBB::Priority syslogPriority() const;
        FBB::Facility syslogFacility() const;

////////////////////


//        std::string const &priority() const;
//        std::string const &facility() const;
//
//        std::string syslogPriorityError() const;
//        std::string syslogFacilityError() const;
//
//        static char const *defaultAgent();
//        static char const *defaultConfigFile();
//        static char const *defaultSyslogIdent();
//        static char const *defaultSyslogFacility();
//        static char const *defaultSyslogPriority();
//        static char const *defaultIPCfile();


};

inline bool Options::daemon() const
{   
    return not d_noDaemon;
}

//inline bool Options::stdout() const
//{   
//    return d_stdout;
//}

//inline bool Options::syslog() const
//{   
//    return d_syslog;
//}
//
//inline bool Options::verbose() const
//{   
//    return d_verbose;
//}

//inline bool Options::signal() const
//{   
//    return d_terminate || d_list;
//}

inline bool Options::terminate() const
{   
    return d_terminate;
}

inline bool Options::list() const
{   
    return d_list;
}

//inline bool Options::log() const
//{   
//    return d_log;
//}

inline std::string const &Options::agent() const
{   
    return d_agent;
}

inline std::string const &Options::basename() const
{   
    return d_arg.basename();
}

//inline std::string const &Options::logName() const
//{   
//    return d_logName;
//}

inline std::string const &Options::ipcFile() const
{   
    return d_IPCfile;
}

//inline std::string const &Options::syslogTag() const
//{   
//    return d_syslogTag;
//}
//
//inline FBB::Priority Options::syslogPriority() const
//{   
//    return d_syslogPriority->second;
//}
//
//inline std::string const &Options::priority() const
//{   
//    return d_syslogPriority->first;
//}
//
//inline std::string Options::syslogPriorityError() const
//{   
//    return d_syslogPriorityError;
//}
//
//inline FBB::Facility Options::syslogFacility() const
//{   
//    return d_syslogFacility->second;
//}
//
//inline std::string Options::syslogFacilityError() const
//{   
//    return d_syslogFacilityError;
//}
//
//inline std::string const &Options::facility() const
//{   
//    return d_syslogFacility->first;
//}
//
//inline char const *Options::defaultSyslogIdent() 
//{
//    return s_defaultSyslogIdent;
//}
//
//inline char const *Options::defaultConfigFile() 
//{
//    return s_defaultConfigFile;
//}
//
//inline char const *Options::defaultAgent() 
//{
//    return s_defaultAgent;
//}
//
//inline char const *Options::defaultSyslogFacility() 
//{
//    return s_defaultSyslogFacility;
//}
//
//inline char const *Options::defaultSyslogPriority() 
//{
//    return s_defaultSyslogPriority;
//}
//
//inline char const *Options::defaultIPCfile() 
//{
//    return s_defaultIPCfile;
//}
        
#endif





