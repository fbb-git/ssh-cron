#include "daemon.ih"

void Daemon::childProcess()
{
    Signal::instance().add(SIGINT, *this);
    Signal::instance().add(SIGTERM, *this);

    thread waiter;          // waits for Enter with --no-daemon

    if (d_options.daemon())
    {
        prepareDaemon();
        imsg << "daemon: starting the scheduler" << endl;
    }
    else
    {
        cout << "Press the `Enter' key to end `" << d_options.basename() <<
                '\'' << endl;  
        waiter = thread(enterThread, this);
        waiter.detach();
        idmsg() << "starting the scheduler" << endl;
    }

    d_cron.fork();

    if (d_options.daemon())
        cleanup();

    throw 0;                    // correctly end the child process at main
}
