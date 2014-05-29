#include "daemon.ih"

void Daemon::terminate() const
{
    imsg << "--terminate requested" << endl;

    ifstream ipcFile;
    Exception::open(ipcFile, Options::instance().ipcFile());

    size_t pid;

    if (not (ipcFile >> pid >> pid))
        throw Exception() << "Can't read the remote process ID from " <<
                                Options::instance().ipcFile();

    imsg << "terminating process " << pid << endl;
    kill(pid, SIGTERM);
}




