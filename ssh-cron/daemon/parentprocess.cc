#include "daemon.ih"

void Daemon::parentProcess()
{
    if (d_options.daemon())
    {
        // write the daemon's pid-file:
        ofstream pidFile;
        Exception::open(pidFile, Options::instance().pidFile());

        pidFile << pid() << endl;
    }
}
