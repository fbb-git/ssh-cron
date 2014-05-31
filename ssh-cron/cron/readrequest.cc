#include "cron.ih"

Cron::Function Cron::readRequest(istream &in)
{
    in.seekg(SharedCondition::size());
    Function value;
    in.read(reinterpret_cast<char *>(&value), sizeof(Function));
    return value;
}
