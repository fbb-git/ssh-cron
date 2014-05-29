#include "cron.ih"

// stop() handles the termination of the child process
// daemon/terminate ends the process via --terminate

void Cron::parentProcess()
{
        // Set up the parent's sides of the pipes
    OFdStream toChild(d_childInput.writeOnly());

    d_toChild = &toChild;

    thread requestThread;

    if (d_options.daemon())
    {
        requestThread = thread(requestHandler, this);
        requestThread.detach();         // ends when main() ends
    }

    defineRunFunction();
    sendCommand("/usr/bin/ssh-add");

    cronLoop();

    if (int status = waitForChild())
        d_options.msg() << "child process " << pid() << 
                            " unexpectedly returned " << status << endl;
    else
        imsg << "child process " << pid() << " ended normally" << endl;
}







