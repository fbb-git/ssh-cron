#ifndef INCLUDED_DAEMON_
#define INCLUDED_DAEMON_

#include <bobcat/fork>

#include "../crondata/crondata.h"

class Options;

class Daemon: public FBB::Fork
{
    Options &d_options;
    CronData d_cronData;

    public:
        Daemon();
        void runParentProcess();

    private:
        void childProcess()     override;
        void parentProcess()    override;
};
        
#endif
