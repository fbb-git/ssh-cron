#include "cron.ih"

void Cron::handleRequests()
{
    ifstream ipcFile;
    Exception::open(ipcFile, Options::instance().ipcFile());
    int shmemId;
    ipcFile >> shmemId;

    SharedStream sharedStream(shmemId);
    SharedCondition cond(sharedStream.attachSharedCondition());
    
    cond.lock();

    size_t index;       // index for CronData elements

    while (true)
    {
        cond.wait();

        Function request = readRequest(sharedStream);
        
        streamsize writeOffset = sharedStream.tellg();

        switch (request)
        {
            case LIST:
            {
                index = 0;
                writeRequest(sharedStream, MORE);
                list(&index, writeOffset, sharedStream);
            }
            break;
        
            case MORE:
                if (index == d_cronData.size())
                    writeRequest(sharedStream, DONE);
                else
                    list(&index, writeOffset, sharedStream);
            break;

            case RELOAD:
                reload(sharedStream);
            break;
            
            default:
            break;
        }
        cond.notify();
    }
}

