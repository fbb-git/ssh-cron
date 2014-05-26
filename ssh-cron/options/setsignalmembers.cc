#include "options.ih"

void Options::setSignalMembers()
{
    if (d_list && d_terminate)
        fmsg << "--list and --terminate cannot both be specified" << endl;

//    string pidFile;
//
//    if (not d_list and not d_terminate)
//        d_PIDfile = pidFile;
//    else if (pidFile.length())
//    {
//        wmsg << "--pid-file ignored with --list and --terminate" << endl;
//        pidFile.clear();
//    }
//
//    if (d_PIDfile.empty())
//        d_PIDfile = s_defaultPIDfile;
}
