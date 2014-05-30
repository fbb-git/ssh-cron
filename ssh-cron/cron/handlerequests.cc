#include "cron.ih"

void Cron::handleRequests()
{
    ifstream ipcFile;
    Exception::open(ipcFile, Options::instance().ipcFile());

    int shmemId;

    ipcFile >> shmemId;

    SharedStream sharedStream(shmemId);

    SharedCondition &cond = sharedStream.attachSharedCondition();
    
    cond.lock();

    size_t index;       // index for CronData elements

    while (true)
    {
        cond.wait();

        Function request;
        
        sharedStream.read(sizeof(SharedCondition), &request);

        switch (request)
        {
            case LIST:
            {
                index = 0;  
                request = MORE;

                sharedStream.write(sizeof(SharedCondition), &request);
                list(&index, sharedStream);
            }
            break;
        
            case MORE:
                if (index != d_cronData.size())
                    list(&index, sharedStream);
                else
                {
                    request = DONE;
                    sharedStream.write(sizeof(SharedCondition), &request);
                }
            break;
            
            default:
            break;
        }
        sharedStream.seekg(0);
        cond.notify();
    }
}

