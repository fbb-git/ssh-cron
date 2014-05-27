#ifndef INCLUDED_DAEMON_
#define INCLUDED_DAEMON_

#include <bobcat/fork>

#include "../crondata/crondata.h"

class Options;

class Daemon: public FBB::Fork
{
    Options &d_options;
    CronData d_cronData;

    int d_shmemId = 0;

    public:
        Daemon();
        void runParentProcess();
        void sendSignal();

    private:
        void checkSyslogParam(char const *label, std::string const &actual, 
                                                 std::string const &err);
        void noEcho() const;
        pid_t cronPid() const;

        void childProcess()                 override;
        void parentProcess()                override;

        void terminate() const;
};
        
#endif


