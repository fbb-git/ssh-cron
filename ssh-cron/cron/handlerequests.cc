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

        shmem.read(sizeof(SharedCondition), &request);

        switch (request)
        {
            default:
            break;

            case TERMINATE:
                d_run = false;
                ipcFile.close();
                unlink(Options::instance().ipcFile().c_str());
                
                shmem.kill();
            return;
        }
    }
}




