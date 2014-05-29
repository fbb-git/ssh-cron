#include "cron.ih"

void Cron::list(size_t *index, SharedMemory &shmem)
{
    shmem.seek(sizeof(size_t), ios::cur);

    streamsize length = 0;

    for (; *index != d_cronData.size(); ++*index)
    {
        ostringstream out;

        out << d_cronData[*index] << endl;

        streamsize outLen = out.str().length();

        if (shmem.offset() + outLen > shmem.maxOffset())
            break;

        length += outLen;
        shmem.write(out.str().data(), outLen);
    }

    shmem.write(sizeof(SharedCondition) + sizeof(Function), &length);
}
