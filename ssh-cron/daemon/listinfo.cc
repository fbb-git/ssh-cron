#include "daemon.ih"

bool Daemon::listInfo(istream &in)
{
    Function function = Cron::readRequest(in);

    imsg << "client: received function " << function << endl;

    if (function < NONE || function == DONE || function > TERMINATE)
        return false;

    string line;
    while (getline(in, line))
        cout << line;

    return true;
}



