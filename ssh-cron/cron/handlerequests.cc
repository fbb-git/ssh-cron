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

    while (true)
    {
        imsg << "server: waiting for requests" << endl;

        cond.wait();

        Function request;
        shmem.read(sizeof(SharedCondition), &request);

        imsg << "server: got request " << request << endl;

        switch (request)
        {
            case LIST:
            {
                request = MORE;

                shmem.write(sizeof(SharedCondition), &request);

                imsg << "server: answers request " << request << 
                        ", now at offset " << shmem.offset() << endl;

                string text("hello world");
                size_t length = text.length();
                shmem.write(&length);

                imsg << "server: writing " << length << " bytes" << 
                        ", now at offset " << shmem.offset() << endl;

                shmem.write(text.c_str(), text.length());

                imsg << "server: wrote " << length << " bytes" << endl;
            }
            break;
        
            case MORE:
                request = DONE;
                shmem.write(sizeof(SharedCondition), &request);
                imsg << "server: answers request " << request << endl;
            break;
            
            default:
            break;
        }
        imsg << "server: notifies the client" << endl;
        shmem.seek(0);
        cond.notify();
    }
}




