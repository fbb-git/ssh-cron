#include "cron.ih"

Cron::Function Cron::readRequest(istream &in)
{
    in.clear();                         // previously executed `read' commands
                                        // may have raised in's failbit.

    in.seekg(SharedCondition::size());
    Function value;
    in.read(reinterpret_cast<char *>(&value), sizeof(Function));
    return value;
}
