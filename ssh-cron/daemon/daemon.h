#ifndef INCLUDED_DAEMON_
#define INCLUDED_DAEMON_

#include <bobcat/fork>

class CronData;

class Daemon: public FBB::Fork
{
    CronData const &d_cronData;
    public:
         Daemon(CronData const &cronData);

    private:
        void childProcess()     override;
        void parentProcess()    override;
};
        
#endif
