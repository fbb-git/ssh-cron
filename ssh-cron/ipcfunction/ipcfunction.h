#ifndef INCLUDED_IPCFUNCTION_
#define INCLUDED_IPCFUNCTION_

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
};
        
#endif
