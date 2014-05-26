#include "cron.ih"

void Cron::handleRequests()
{
    ifstream pidFile;
    Exception::open(pidFile, Options::instance().pidFile());

    int shmemId;

    pidFile >> shmemId;

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
                pidFile.close();
                unlink(Options::instance().pidFile().c_str());
                
                shmem.kill();
            return;
        }
    }
}




