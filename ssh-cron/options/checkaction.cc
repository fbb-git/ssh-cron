#include "options.ih"

void Options::checkAction()
{
    if (d_list + d_reload + d_terminate + not d_daemon > 1)
    {
        fmsg << "incompatible options:";

        if (d_list)
            fmsg << " --list";

        if (d_reload)
            fmsg << " --reload";

        if (d_terminate)
            fmsg << " --terminate";
        
        if (not d_daemon)
            fmsg << " --no-daemon";

        fmsg << endl;
    }

    if (d_arg.nArgs == 0)
    {
        if (not (d_list || d_terminate))
            fmsg << "config file required" << endl;
    }
    else if (d_list || d_terminate)
        fmsg << "crontab file incompatible with --list and --terminate" <<
                                                                        endl;
}

