#include "cron.ih"

void Cron::parentProcess()
{
        // Set up the parent's sides of the pipes
    IFdStream fromChild(d_childOutput.readOnly());
    OFdStream toChild(d_childInput.writeOnly());

    d_fromChild = &fromChild;
    d_toChild = &toChild;

    d_selector.addReadFd(d_childOutput.readFd());

    thread requestThread(requestHandler, this);

    try
    {
        sendCommand("/bin/echo hello world");
        sendCommand("/usr/bin/ssh-add");
        cronLoop();

        sendCommand("exit");
        // kill(pid(), SIGTERM);
        //log << "Child process " << pid() << " got SIGTERM" << endl;
    }
    catch (Leave)
    {}

    requestThread.join();

    imsg << "child returns " << waitForChild() << endl;
}


