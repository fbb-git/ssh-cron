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
        void foreground();          // don't fork, just call the child process
        void daemonize();           // run the daemon in the background
        void ipc();                 // do the other commands, involving ipc

    private:
        void createIPCfile();


        void noEcho() const;
        pid_t cronPid() const;

        void childProcess()                 override;
        void parentProcess()                override;

        void terminate() const;
};
        
#endif


