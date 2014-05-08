#include "daemon.ih"

void Daemon::childProcess()
{
    prepareDaemon();

    Cron cron;
    cron.fork();
    // to be logged:  "Daemon's child's parent process ends\n";

    throw 0;                    // correctly end the child process at main
}
