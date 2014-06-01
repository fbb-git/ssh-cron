#include "daemon.ih"

void Daemon::list()
{
    imsg << "--list requested" << endl;

    IPCInfo info = getIPCInfo();

    SharedStream sharedStream(info.shmemID);

    SharedCondition cond(sharedStream.attachSharedCondition(0));
    
    cond.lock();
    Cron::writeRequest(sharedStream, LIST);

    do
    {
        imsg << d_options.basename() << ": notifying the daemon" << endl;
        cond.notify();          // notify the server (waiting remote process)

                                // now wait for the answer
        cv_status status = cond.wait_for(chrono::seconds(2));
        if (status == cv_status::timeout)
        {
            cond.unlock();
            fmsg << "--list request: no response from process " << 
                        info.pid << endl;
        }
        imsg << d_options.basename() << ": received a reply" << endl;

    }
    while (listInfo(sharedStream));     // process the reply

    cond.unlock();              // allow the server to wait again
}





