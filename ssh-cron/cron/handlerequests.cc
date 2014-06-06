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
        idmsg() << "waiting for requests" << endl;
        cond.wait();

        Function request = readRequest(sharedStream);

        if (request > TERMINATE)
        {
            scheduler() << "received invalid function request " << request << 
                                                                        endl;
            continue;
        }

        (request == MORE ? idmsg() : scheduler()) << "received request " << 
                            nameOf(request) << endl;
        
        streamsize writeOffset = sharedStream.tellg();

        switch (request)
        {
            case LIST:
            {
                index = 0;
                idmsg() << "answering MORE" << endl;
                writeRequest(sharedStream, MORE);
                list(&index, writeOffset, sharedStream);
            }
            break;
        
            case MORE:
                if (index != d_cronData.size())
                    list(&index, writeOffset, sharedStream);
                else
                {
                    idmsg() << "answering DONE" << endl;
                    writeRequest(sharedStream, DONE);
                }
            break;

            case RELOAD:
                reload(sharedStream);
            break;
            
            default:
            break;
        }
        idmsg() << "notifying the requestor" << endl;
        cond.notify();
    }
}



