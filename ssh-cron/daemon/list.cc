#include "daemon.ih"

bool Daemon::list(istream &in)
{
    in.clear();
    Function function = Cron::readRequest(in);

    if (function > TERMINATE)
    {
        basename() << "received corrupted function request, value = " <<
                                                            function << endl;
        return false;
    }
        
    idmsg() << "received " << nameOf(function) << endl;

    if (function == DONE)
        return false;

    string line;
    while (getline(in, line))
        cout << line << '\n';

    return true;
}


