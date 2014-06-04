#include "daemon.ih"

Daemon::Daemon()
:
    d_options(Options::instance()),
    d_cron(d_cronData)
{
    if (not d_options.cronfile())       // no file command-line argument
        return;

    ifstream in;
    Exception::open(in, ArgConfig::instance()[0]);

    Parser parser(in, d_cronData);      // parse the input file
    parser.parse();                     // filling d_cronData

    if (d_cronData.size() == 0)         // warn if no commands
        wmsg << "no cron-commands to execute." << endl;
}
