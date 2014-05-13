#include "options.ih"

void Options::setSignalMembers()
{
                                    // see if -t has a pidfile
    d_terminate = d_arg.option(&d_PIDfile, 't');
    d_list = d_arg.option(&d_PIDfile, 'l');

    if (d_list && d_terminate)
        fmsg << "--list and --terminate cannot both be specified" << endl;

    string pidFile;
    d_arg.option(&pidFile, 'p');      // see if '-p' has a pidFile

    if (not d_list and not d_terminate)
        d_pidFile = pidFile;
    else if (pidFile.length())
    {
        wmsg << "--pid-file ignored with --list and --terminate" << endl;
        pidFile.clear();
    }

    if (d_PIDfile.empty())
        d_PIDfile = s_defaultPIDfile;
}
