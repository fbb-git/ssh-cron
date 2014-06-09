#include "cron.ih"

void Cron::writeRequest(ostream &out, Function value)
{
    out.seekp(SharedCondition::size());     // the shared cond. is at offset 0
    out.write(reinterpret_cast<char const *>(&value), sizeof(Function));
}
