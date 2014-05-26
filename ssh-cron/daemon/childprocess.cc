#include "daemon.ih"

void Daemon::childProcess()
{
    Cron cron(d_stdMsg, d_cronData);

    if (d_options.daemon())
        prepareDaemon();

    cron.fork();

        // when the child process ends it throws away its own pid file:
    ifstream pidFile(d_options.pidFile());
    pid_t pid;
    if (pidFile >> pid && pid == getpid())
    {
        pidFile.close();
        unlink(d_options.pidFile().c_str());
    }

    throw 0;                    // correctly end the child process at main
}
