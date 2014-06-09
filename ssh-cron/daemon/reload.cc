#include "daemon.ih"

void Daemon::reload()
{
    basename() << "--reload" << endl;

        // send the name of the cron-file to the daemon
    unique_ptr<char> path(realpath(ArgConfig::instance()[0], 0));

        // verify the availability of the IPC file
    IPCInfo info = getIPCInfo();

    SharedStream sharedStream(info.shmemID);

    SharedCondition cond(sharedStream.attachSharedCondition(0));
    
    cond.lock();

    for (size_t attempt = 0; attempt != 3; ++attempt)
    {
        Cron::writeRequest(sharedStream, RELOAD);

        // the offset is just beyond the request

        // retrieve the pass phrase
        string passPhrase = askPassPhrase();

        sharedStream << passPhrase << '\n' << path.get() << endl;
        sharedStream.truncate(sharedStream.tellp());

        idmsg() << "notifying the daemon: RELOAD " << path.get() << endl;
        cond.notify();

        cv_status status = cond.wait_for(chrono::seconds(5));
        cond.unlock();

        if (status != cv_status::timeout)
        {
            // show the scheduled jobs to be reloaded
            cout << '\n' << 
                    d_cronData << endl;
            return;
        }

        cout << "Invalid pass phrase.\n" << endl;
    }
    
    cout << "Giving up after three attempts." << endl;
}
