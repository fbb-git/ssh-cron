#include "daemon.ih"

Daemon::Daemon()
:
    d_options(Options::instance()),
    d_cron(d_cronData)
{
    if (not d_options.cronfile())
        return;

    ifstream in;
    Exception::open(in, ArgConfig::instance()[0]);

    Parser parser(in, d_cronData);
    parser.parse();

    if (d_cronData.size() == 0)
        throw Exception() << "Terminating: no viable cron-commands.";
}
