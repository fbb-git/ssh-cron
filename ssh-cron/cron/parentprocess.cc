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
    
    d_options.msg() << "scheduler: executing /usr/bin/ssh-add" << endl;
    sendCommand("/usr/bin/ssh-add");

    cronLoop();

    if (int status = waitForChild())
        scheduler() << "ssh-agent (pid = " << pid() << ") returned " << 
                                                            status << endl;
    else
        idmsg() << "normal end of ssh-agent (pid = " << pid() << ')' << endl;
}







