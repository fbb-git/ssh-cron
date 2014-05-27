#include "daemon.ih"

void Daemon::childProcess()
{
    Cron cron(d_cronData);

    if (d_options.daemon())
        prepareDaemon();

    cron.fork();

        // when the child process ends it throws away its own pid file:
    ifstream ipcFile(d_options.ipcFile());
    size_t shmemID;
    if (ipcFile >> shmemID)
    {
        ipcFile.close();
        unlink(d_options.ipcFile().c_str());
    }

    throw 0;                    // correctly end the child process at main
}
