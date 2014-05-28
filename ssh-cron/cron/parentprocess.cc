#include "cron.ih"

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
        requestThread.detach();
    }

    try
    {
        sendCommand("/usr/bin/ssh-add");
        cronLoop();

        sendCommand("exit");
    }
    catch (Leave)
    {}

//    if (d_options.daemon())
//    {
//        imsg << "waiting for the thread" << endl;
//
//        requestThread.join();

    imsg << "child returns " << waitForChild() << endl;
}



