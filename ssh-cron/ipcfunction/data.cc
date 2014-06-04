#include "ipcfunction.ih"

LinearMap<IPCFunction::Function, char const *> IPCFunction::s_nameMap = 
{
    {NONE,      "NONE"},
    {DONE,      "DONE"},
    {LIST,      "LIST"},
    {MORE,      "MORE"},
    {RELOAD,    "RELOAD"},
    {TERMINATE, "TERMINATE"}
};
