#include "options.ih"

void Options::checkAction() const
{
            // only one of these options may be specified
    if (d_list + d_reload + d_terminate + d_noDaemon > 1)
    {
        fmsg << "incompatible options:";

        if (d_list)
            fmsg << " --list";

        if (d_reload)
            fmsg << " --reload";

        if (d_terminate)
            fmsg << " --terminate";
        
        if (d_noDaemon)
            fmsg << " --no-daemon";

        fmsg << endl;
    }

        // if no argument then --list or --terminate are required
    if (d_arg.nArgs() == 0)
    {
        if (not (d_list || d_terminate))
            fmsg << "crontab file required" << endl;
    }
    else if (d_list || d_terminate)
        // --list and --terminate cannot accept a crontab file
        fmsg << "crontab file incompatible with --list and --terminate" <<
                                                                        endl;
}





