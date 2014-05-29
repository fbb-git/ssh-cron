#include "daemon.ih"

void Daemon::request(SharedCondition &cond, Function function)
{
    d_shmem.seek(0);
    cond.lock();

    d_shmem.write(sizeof(SharedCondition), &function);
    imsg << "client: requests function " << function << endl;
}
