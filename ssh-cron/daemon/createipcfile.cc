#include "daemon.ih"

// called from daemonize()
    
void Daemon::createIPCfile()
{
    string const &ipcFile = d_options.ipcFile();

    unique_ptr<char> buffer(new char[ipcFile.length() + 6 + 1]);
    strcpy(buffer.get() + ipcFile.copy(buffer.get(), string::npos), "XXXXXX");

    int fd = mkstemp(buffer.get());
    if (fd != -1)
    {
        close(fd);
        fd = rename(buffer.get(), d_options.ipcFile().c_str());
    }

    if (fd == -1)
        fmsg << "cannot create ipc file " << d_options.ipcFile() << endl;
}
