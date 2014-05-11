#include "main.ih"

#include "parser/parser.h"

// Room for Args initialization
namespace   // the anonymous namespace can be used here
{
    Arg::LongOption longOptions[] =
    {
        Arg::LongOption("help", 'h'),
        Arg::LongOption("no-daemon", Arg::None),
        Arg::LongOption("no-syslog", Arg::None),
        Arg::LongOption("pid-file", 'p'),

        Arg::LongOption("stdout", 's'),

        Arg::LongOption("syslog-facility", Arg::Required),
        Arg::LongOption("syslog-priority", Arg::Required),
        Arg::LongOption("syslog-tag", Arg::Required),

        Arg::LongOption("verbose", Arg::None),
        Arg::LongOption("version", 'v'),
    };

    auto longEnd = longOptions + sizeof(longOptions) / sizeof(longOptions[0]);
}

int main(int argc, char **argv)
try
{
    ArgConfig &arg = ArgConfig::initialize("hlp:sv", 
                        longOptions, longEnd, argc, argv);
    
    arg.versionHelp(usage, Icmbuild::version, 0);

    Options options;
    CronData cronData;

    Parser parser(options, cronData);
    parser.parse();

    Cron cron(cronData);
    cron.runParentProcess();
    
//    Daemon daemon(cronData);
//    daemon.fork();
}
catch (exception const &exc)
{
    cerr << "Exception: " << exc.what() << endl;
}
catch (int x)
{
    cout << "The child terminates with: " << x << endl;
    return x;
}
catch (bool)
{
    return 0;
}
