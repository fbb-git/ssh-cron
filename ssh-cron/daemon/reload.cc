#include "daemon.ih"

void Daemon::reload()
{
    unique_ptr<char> path(realpath(ArgConfig::instance()[0], 0));

    cout << d_cronData << endl;

    imsg << "Reloading the daemon with " << path.get() << endl;

    IPCInfo info = getIPCInfo();

    SharedStream sharedStream(info.shmemID);

    SharedCondition cond(sharedStream.attachSharedCondition(0));
    
    cond.lock();
    Cron::writeRequest(sharedStream, RELOAD);
    sharedStream << path.get() << endl;
    cond.notify();
    cond.unlock();
}
