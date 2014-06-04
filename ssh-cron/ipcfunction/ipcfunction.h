#ifndef INCLUDED_IPCFUNCTION_
#define INCLUDED_IPCFUNCTION_

#include <bobcat/linearmap>

struct IPCFunction
{
    enum Function: unsigned int
    {
        NONE,
        DONE,
        LIST,
        MORE,
        RELOAD,
        TERMINATE
    };

    private:
        static FBB::LinearMap<Function, char const *> s_nameMap;

    public:
        static char const *nameOf(Function fun);
};

inline char const *IPCFunction::nameOf(Function fun)
{
    return s_nameMap[fun];
}

#endif




