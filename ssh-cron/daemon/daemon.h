#ifndef INCLUDED_DAEMON_
#define INCLUDED_DAEMON_

#include <memory>

#include <bobcat/fork>
#include <bobcat/multistreambuf>
#include <bobcat/log>

#include "../crondata/crondata.h"

class Options;

namespace FBB
{
    class SyslogStream;
}

class Daemon: public FBB::Fork
{
    Options &d_options;
    CronData d_cronData;

    std::unique_ptr<FBB::SyslogStream> d_syslog;
    FBB::Log d_log;

    FBB::MultiStreambuf d_multiStreambuf;
    std::ostream d_stdMsg;                  // d_stdMsg is used for messages
                                            // that should unconditionally be
                                            // shown. imsg is used when 
                                            // --verbose was requested,
                                            // wmsg is for warnings
                                            // emasg is for errors, used by 
                                            // the compiler.
    int d_shmemId = 0;

    public:
        Daemon();
        void runParentProcess();
        void sendSignal();

    private:
        void setupStdMsg();
        void checkSyslogParam(char const *label, std::string const &actual, 
                                                 std::string const &err);
        void setupDaemonMsg();
        void setupNonDaemonMsg();

        void noEcho() const;
        pid_t cronPid() const;

        void childProcess()                 override;
        void parentProcess()                override;

        void terminate() const;
};
        
#endif


