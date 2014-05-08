#ifndef INCLUDED_DAEMON_
#define INCLUDED_DAEMON_

#include <bobcat/fork>

class Daemon: public FBB::Fork
{
    void childProcess()     override;
    void parentProcess()    override;
};
        
#endif
