#include "cron.ih"

// stop() handles the termination of the child process
// daemon/terminate ends the process via --terminate

void Cron::parentProcess()
{
        // Set up the parent's sides of the pipes
    IFdStream fromChild(d_childOutput.readOnly());
    OFdStream toChild(d_childInput.writeOnly());

    d_fromChild = &fromChild;
    d_toChild = &toChild;

    d_selector.addReadFd(d_childOutput.readFd());

    thread requestThread;

    if (d_options.daemon())
    {
        requestThread = thread(requestHandler, this);
        requestThread.detach();         // ends when main() ends
    }

    try
    {
        defineRunFunction();
        sendCommand("/usr/bin/ssh-add");
        cronLoop();
    }
    catch (Leave)
    {}

    imsg << "child returns " << waitForChild() << endl;
}



