#include "daemon.ih"

Daemon::Daemon()
{
    Parser parser(d_cronData);
    parser.parse();

    if (d_cronData.nCronCommands() == 0)
        throw Exception() << "Terminating: no viable cron-commands.";
}
