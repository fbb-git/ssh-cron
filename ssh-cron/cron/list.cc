#include "cron.ih"

void Cron::list(size_t *index, SharedStream &sharedStream)
{
    for (; *index != d_cronData.size(); ++*index)
    {
        streamsize lastOK = sharedStream.tellp();

        if (not (sharedStream << d_cronData[*index] << endl))
        {
            sharedStream.truncate(lastOK);
            break;
        }
    }
}
