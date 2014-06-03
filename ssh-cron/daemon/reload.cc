#include "daemon.ih"

void Daemon::reload()
{
    unique_ptr<char> path(realpath(ArgConfig::instance()[0], 0));

    cout << d_cronData << endl;

    imsg << "Reloading the daemon with " << path.get() << endl;
}
