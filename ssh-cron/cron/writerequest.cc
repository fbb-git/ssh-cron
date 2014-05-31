#include "cron.ih"

void Cron::writeRequest(ostream &out, Function value)
{
    out.seekp(SharedCondition::size());
    out.write(reinterpret_cast<char const *>(&value), sizeof(Function));
}
