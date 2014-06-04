#include "daemon.ih"

void Daemon::listRequest()
{
    d_options.msg() << "--list issued" << endl;

    IPCInfo info = getIPCInfo();

    SharedStream sharedStream(info.shmemID);

    SharedCondition cond(sharedStream.attachSharedCondition(0));
    
    cond.lock();
    Cron::writeRequest(sharedStream, LIST);

    do
    {
        imsg << d_options.basename() << ": notifying (LIST) the daemon " << 
                endl;

        cond.notify();          // notify the server (waiting remote process)

                                // now wait for the answer
        cv_status status = cond.wait_for(chrono::seconds(2));
        if (status == cv_status::timeout)
        {
            cond.unlock();
            fmsg << "--list: no response from process " << info.pid << endl;
        }
    }
    while (list(sharedStream)); // process the reply

    cond.unlock();              // allow the daemon to return to its waiting
                                // state
}





