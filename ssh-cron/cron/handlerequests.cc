#include "cron.ih"

void Cron::handleRequests()
{
    ifstream ipcFile;
    Exception::open(ipcFile, Options::instance().ipcFile());

    int shmemId;

    ipcFile >> shmemId;

    SharedMemory shmem(shmemId);
    SharedCondition &cond = SharedCondition::attach(shmem);
    
    while (true)
    {
        cond.lock();

        cond.wait();

        Function request;

        shmem.read(&request, sizeof(SharedCondition));

        switch (request)
        {
            default:
            break;
        }
    }
}




