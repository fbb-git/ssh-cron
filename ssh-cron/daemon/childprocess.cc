#include "daemon.ih"

void Daemon::childProcess()
{
    Signal::instance().add(SIGINT, *this);
    Signal::instance().add(SIGTERM, *this);

    thread waiter;

    if (d_options.daemon())
        prepareDaemon();
    else
    {
        cout << "Press the `Enter' key to end `" << d_options.basename() <<
                '\'' << endl;  
        waiter = thread(enterThread, this);
        waiter.detach();
    }

    d_cron.fork();              // start the scheduler and ssh-agent

    if (d_options.daemon())
        cleanup();

    throw 0;                    // correctly end the child process at main
}
