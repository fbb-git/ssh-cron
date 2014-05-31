#include "cron.ih"

void Cron::list(size_t *index, streamsize offset, SharedStream &out)
{
    out.seekp(offset);

    for (; *index != d_cronData.size(); ++*index)
    {
        streamsize lastOK = out.tellp();

        if (not (out << d_cronData[*index] << endl))
        {
            out.truncate(lastOK);
            break;
        }
    }
}
