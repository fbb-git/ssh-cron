#include "cron.ih"

void Cron::list(size_t *index, streamsize offset, SharedStream &out)
{
    out.seekp(offset);
    out.truncate(offset);           // clear any previous contents

    if (*index == 0)                // write an initial \n separator
        out.put('\n');

    for (; *index != d_cronData.size(); ++*index)
    {
        streamsize lastOK = out.tellp();

        if (not (out << d_cronData[*index] << endl))
        {
            out.truncate(lastOK);
            return;
        }
    }
    out << endl;
}
