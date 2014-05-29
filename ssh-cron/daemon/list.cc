#include "daemon.ih"

void Daemon::list()
{
    imsg << "--list requested" << endl;

    size_t pid = getSharedMemory();

    SharedCondition &cond = SharedCondition::attach(d_shmem);
    
    request(cond, LIST);        // returns at shmem offset 0 (= at cond)
    do
    {
        imsg << "client: notifies the server" << endl;
        cond.notify();          // notify the server (waiting remote process)

                                // now wait for the answer
        cv_status status = cond.wait_for(chrono::seconds(2));
        if (status == cv_status::timeout)
        {
            cond.unlock();
            fmsg << "--list request: no response from process " << pid << 
                                                                        endl;
        }
        imsg << "client: received a reply" << endl;

    }
    while (listInfo(cond));     // process the reply

    cond.unlock();              // allow the server to wait again
}
