#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <memory>

#include <bobcat/argconfig>
#include <bobcat/linearmap>
#include <bobcat/log>
#include <bobcat/multistreambuf>
#include <bobcat/syslogstream>

#include "../ipcfunction/ipcfunction.h"

namespace FBB
{
    class SyslogStream;
}

class Options: public IPCFunction
{
    FBB::ArgConfig &d_arg;

    std::unique_ptr<FBB::SyslogStream> d_syslog;
    FBB::Log d_log;

    FBB::MultiStreambuf d_multiStreambuf;
    std::ostream d_msg;                     // d_msg handles all messages to
                                            // syslog and/or d_log

    std::string d_agent;
    std::string d_IPCfile;
    std::string d_mailer;

    FBB::LinearMap<std::string, FBB::Facility>::const_iterator 
                                                        d_syslogFacility;
    FBB::LinearMap<std::string, FBB::Priority>::const_iterator 
                                                        d_syslogPriority;
    bool d_foreground;
    bool d_list;
    bool d_reload;
    bool d_terminate;
    bool d_forced;

    Function d_ipcFunction = NONE;

    static Options *s_options;

    static FBB::Facility    s_defaultSyslogFacility;
    static FBB::Priority    s_defaultSyslogPriority;
    static char const       s_defaultAgent[];
    static char const       s_defaultConfigFile[];
    static char const       s_defaultIPCfile[];
    static char const       s_defaultSyslogIdent[];
    static char const       s_defaultMailer[];

    static FBB::LinearMap<std::string, FBB::Facility> const 
                                                       s_syslogFacilities;
    static FBB::LinearMap<std::string, FBB::Priority> const 
                                                       s_syslogPriorities;

    public:
        static Options &instance();

        Options(Options const &other) = delete;

        bool foreground() const;
        bool daemon() const;
        bool ipc() const;
        bool cronfile() const;
        bool reload() const;
        bool forced() const;

        Function ipcFunction() const;

        std::string const &agent() const;
        std::string const &basename() const;
        std::string const &ipcFile() const;
        std::string const &mailer() const;

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

inline bool Options::foreground() const
{   
    return d_foreground;
}

inline bool Options::daemon() const
{   
    return not d_foreground;
}

inline bool Options::forced() const
{   
    return d_forced;
}

inline bool Options::reload() const
{   
    return d_reload;
}

inline bool Options::ipc() const
{   
    return d_list || d_terminate || d_reload;
}

inline bool Options::cronfile() const
{   
    return d_arg.nArgs();
}

inline IPCFunction::Function Options::ipcFunction() const
{   
    return d_ipcFunction;
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

inline std::string const &Options::mailer() const
{   
    return d_mailer;
}

#endif





