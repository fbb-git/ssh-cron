#include "daemon.ih"

void Daemon::cleanup()      // only called by daemons
{
    d_shmem.kill();

        // when the child process ends it throws away its own pid file:
    unlink(d_options.ipcFile().c_str());

}
