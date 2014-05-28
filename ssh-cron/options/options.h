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
    std::ostream d_msg;                     // d_msg handles all messages to
                                            // syslog and/or d_log

    std::string d_agent;
    std::string d_IPCfile;

    FBB::LinearMap<std::string, FBB::Facility>::const_iterator 
                                                        d_syslogFacility;
    FBB::LinearMap<std::string, FBB::Priority>::const_iterator 
                                                        d_syslogPriority;
    bool d_noDaemon;
    bool d_list;
    bool d_reload;
    bool d_terminate;

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

        std::ostream &msg();

        static void usage(std::string const &progname);

    private:
        Options();

        bool setSyslog();

        void checkAction() const;
        void loadConfigFile();

        std::string syslogTag() const;
        FBB::Priority syslogPriority() const;
        FBB::Facility syslogFacility() const;
};

inline std::ostream &Options::msg()
{
    return d_msg;
}

inline bool Options::daemon() const
{   
    return not d_noDaemon;
}

inline bool Options::terminate() const
{   
    return d_terminate;
}

inline bool Options::list() const
{   
    return d_list;
}

inline std::string const &Options::agent() const
{   
    return d_agent;
}

inline std::string const &Options::basename() const
{   
    return d_arg.basename();
}

inline std::string const &Options::ipcFile() const
{   
    return d_IPCfile;
}

#endif





