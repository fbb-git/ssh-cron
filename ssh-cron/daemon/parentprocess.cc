#include "daemon.ih"

void Daemon::parentProcess()
{
    if (not d_options.daemon())
        return;

    // write the daemon's pid-file:
    ofstream pidFile;
    Exception::open(pidFile, Options::instance().pidFile());

    pidFile << pid() << endl;
}
