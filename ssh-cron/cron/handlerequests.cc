#include "cron.ih"

void Cron::handleRequests()
{
    ifstream ipcFile;
    Exception::open(ipcFile, Options::instance().ipcFile());

    int shmemId;

    ipcFile >> shmemId;

    SharedMemory shmem(shmemId);
    SharedCondition &cond = SharedCondition::attach(shmem);
    
    cond.lock();

    size_t index;       // index for CronData elements

    while (true)
    {
        cond.wait();

        Function request;
        shmem.read(sizeof(SharedCondition), &request);

        switch (request)
        {
            case LIST:
            {
                index = 0;  
                request = MORE;

                shmem.write(sizeof(SharedCondition), &request);
                list(&index, shmem);
            }
            break;
        
            case MORE:
                if (index != d_cronData.size())
                    list(&index, shmem);
                else
                {
                    request = DONE;
                    shmem.write(sizeof(SharedCondition), &request);
                }
            break;
            
            default:
            break;
        }
        shmem.seek(0);
        cond.notify();
    }
}





