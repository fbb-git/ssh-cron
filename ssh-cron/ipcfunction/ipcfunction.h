#ifndef INCLUDED_IPCFUNCTION_
#define INCLUDED_IPCFUNCTION_

struct IPCFunction
{
    enum Function
    {
        NONE,
        DONE,
        LIST,
        MORE,
        RELOAD,
        TERMINATE
    };
};
        
#endif
