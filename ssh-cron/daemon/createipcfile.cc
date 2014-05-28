#include "daemon.ih"

void Daemon::createIPCfile()
{
    char buffer[7] = "XXXXXX";              

    int fd = mkstemp(buffer);
    if (fd != -1)
    {
        close(fd);
        fd = rename(buffer, d_options.ipcFile().c_str());
    }

    if (fd == -1)
        fmsg << "cannot create ipc file " << d_options.ipcFile() << endl;
}
