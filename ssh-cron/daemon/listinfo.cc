#include "daemon.ih"

bool Daemon::listInfo(istream &in)
{
    in.clear();
    Function function = Cron::readRequest(in);

    imsg << "daemon: received function " << nameOf(function) << endl;

    if (function == DONE)
        return false;

    if (function > TERMINATE)
    {
        d_options.msg() << 
                "daemon: received corrupted function request, value = " <<
                function << endl;
        return false;
    }
        
    string line;
    while (getline(in, line))
        cout << line << '\n';

    return true;
}



