#include "daemon.ih"

void Daemon::terminate() const
{
    ifstream ipcFile;
    Exception::open(ipcFile, Options::instance().ipcFile());

    int shmemId;

    ipcFile >> shmemId;

    SharedMemory shmem(shmemId);
    SharedCondition &cond = SharedCondition::attach(shmem);
    
    Cron::Function request = Cron::TERMINATE;
    cond.lock();

    shmem.seek(sizeof(SharedCondition));

    shmem.write(request, sizeof(SharedCondition));

    shmem.seek(0);

    cond.notify();
    cond.unlock();
}




