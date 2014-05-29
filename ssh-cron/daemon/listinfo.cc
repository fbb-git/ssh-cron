#include "daemon.ih"

bool Daemon::listInfo(SharedCondition &cond)
{
    Function function;

    d_shmem.read(sizeof(SharedCondition), &function);

    imsg << "client: received function " << function << endl;

    if (function < NONE || function == DONE || function > TERMINATE)
        return false;

    imsg << "client: shmem at offset " << d_shmem.offset() << endl;


    streamsize size = 0;                    // read the amount of info

    d_shmem.read(&size);

    imsg << "client: " << size << " bytes are available" << endl;

    if (size + d_shmem.offset() > d_shmem.maxOffset())
        return false;

    char *buffer = new char[size];
    d_shmem.read(buffer, size);
    
    cout.write(buffer, size);
    delete[] buffer;

    return true;
}



