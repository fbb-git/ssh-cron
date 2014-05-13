#include "daemon.ih"

Daemon::Daemon()
:
    d_options(Options::instance()),
    d_stdMsg(&d_multiStreambuf)
{
    Parser parser(d_cronData);
    parser.parse();

    if (d_cronData.nCronCommands() == 0)
        throw Exception() << "Terminating: no viable cron-commands.";

    setupStdMsg();

    if (d_options.daemon())
        setupDaemonMsg();
    else
        setupNonDaemonMsg();
}
