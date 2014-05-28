#include "daemon.ih"

void Daemon::childProcess()
{
    Signal::instance().add(SIGINT, *this);
    Signal::instance().add(SIGTERM, *this);

    if (d_options.daemon())
        prepareDaemon();

    d_cron.fork();              // start the scheduler and ssh-agent

    if (d_options.daemon())
        cleanup();

    throw 0;                    // correctly end the child process at main
}
