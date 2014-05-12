#include "cron.ih"

void Cron::parentProcess()
{
        // Set up the parent's sides of the pipes
    IFdStream fromChild(d_childOutput.readOnly());
    OFdStream toChild(d_childInput.writeOnly());

    d_fromChild = &fromChild;
    d_toChild = &toChild;

    d_selector.addReadFd(d_childOutput.readFd());

    try
    {
        sendCommand("/bin/echo hello world");
        sendCommand("/usr/bin/ssh-add");
        cronLoop();
    }
    catch (Leave)
    {}

    d_log << "The child returns value " << waitForChild() << endl;
}


