#ifndef INCLUDED_DAEMON_
#define INCLUDED_DAEMON_

#include <bobcat/fork>

#include "../crondata/crondata.h"

class Daemon: public FBB::Fork
{
    CronData d_cronData;

    public:
        Daemon();
        void runParentProcess();

    private:
        void childProcess()     override;
        void parentProcess()    override;
};
        
#endif
