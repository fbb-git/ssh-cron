#include "main.ih"

// Room for Args initialization
namespace   // the anonymous namespace can be used here
{
    Arg::LongOption longOptions[] =
    {
                // only interpreted from the command-line

        Arg::LongOption("help", 'h'),
        Arg::LongOption("version", 'v'),

        Arg::LongOption("list", 'l'),
        Arg::LongOption("no-daemon", Arg::None),
        Arg::LongOption("reload", 'r'),
        Arg::LongOption("terminate", 't'),

        Arg::LongOption("config", 'c'),

                // all options below are also interpreted when specified by
                // the config file

        Arg::LongOption("agent", Arg::Required),
        Arg::LongOption("ipc-file", 'i'),
        Arg::LongOption("log",  'L'),

        Arg::LongOption("syslog", Arg::None),
        Arg::LongOption("syslog-facility", Arg::Required),
        Arg::LongOption("syslog-priority", Arg::Required),
        Arg::LongOption("syslog-tag", Arg::Required),

        Arg::LongOption("verbose", Arg::None),
    };

    auto longEnd = longOptions + sizeof(longOptions) / sizeof(longOptions[0]);
}

int main(int argc, char **argv)
try
{
    ArgConfig &arg = ArgConfig::initialize("c:hi:lL:rtv", 
                        longOptions, longEnd, argc, argv);
    
    arg.versionHelp(Options::usage, Icmbuild::version, 0);

    Daemon daemon;

    if (not Options::instance().daemon())
        daemon.runParentProcess();
    else
        daemon.fork();
}
catch (exception const &exc)
{
    if (exc.what() != to_string(fmsg.id()))
        cerr << exc.what() << endl;
    return 1;
}
catch (int x)
{
    return ArgConfig::instance().option("hv") ? 0 : x;
}


