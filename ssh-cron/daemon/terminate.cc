#include "daemon.ih"

void Daemon::terminate() const
{
    imsg << "--terminate requested" << endl;

    ifstream ipcFile;
    Exception::open(ipcFile, Options::instance().ipcFile());

    int shmemId;

    if (not (ipcFile >> shmemId))
        throw Exception() << "Can't read the shared segment id from " <<
                                Options::instance().ipcFile();

    imsg << "shared memory ID: " << shmemId << endl;

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




