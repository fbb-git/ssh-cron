#include "daemon.ih"

void Daemon::reload()
{
    basename() << "--reload" << endl;

        // send the name of the cron-file to the daemon

    unique_ptr<char> path(realpath(ArgConfig::instance()[0], 0));

    cout << d_cronData << endl;

    IPCInfo info = getIPCInfo();

    SharedStream sharedStream(info.shmemID);

    SharedCondition cond(sharedStream.attachSharedCondition(0));
    
    cond.lock();
    Cron::writeRequest(sharedStream, RELOAD);
    sharedStream << path.get() << endl;
    idmsg() << "notifying the daemon: RELOAD " << path.get() << endl;
    cond.notify();
    cond.unlock();
}
