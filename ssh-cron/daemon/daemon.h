#ifndef INCLUDED_DAEMON_
#define INCLUDED_DAEMON_

#include <bobcat/fork>
#include <bobcat/sharedmemory>
#include <bobcat/signal>

#include "../crondata/crondata.h"
#include "../cron/cron.h"

class Options;

class Daemon: public FBB::Fork, public FBB::SignalHandler
{
    Options &d_options;
    CronData d_cronData;
    Cron d_cron;

    FBB::SharedMemory d_shmem;

    public:
        Daemon();
        void run();

    private:
        void foreground();          // don't fork, just call the child process
        void daemonize();           // run the daemon in the background
        void ipc();                 // do the other commands, involving ipc

        void createIPCfile();
        void cleanup();

        void parentProcess()                override;
        void childProcess()                 override;
        void signalHandler(size_t signum)   override;

        void terminate() const;
};
        
#endif


