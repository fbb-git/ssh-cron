#include "cron.ih"

void Cron::parentProcess()
{
        // Set up the parent's sides of the pipes
    IFdStream fromChild(d_childOutput.readOnly());
    OFdStream toChild(d_childInput.writeOnly());

        // write lines to the child, read its output
    string line;

    Selector selector;
    selector.addReadFd(d_childOutput.readFd());

    string commands[] = 
    {
        "echo /usr/bin/ssh-add",
        ""
    };

    ofstream out("/tmp/ssh-cron.log");

    try
    {
        for (string &line: commands)
        {
            if (line.empty())
            {
                kill(pid(), SIGTERM);
                break;
            }
    
            toChild << line << endl;
    
            selector.setAlarm(0, 300000);
            try
            {
                while (selector.wait() > 0)
                {
                    if (not getline(fromChild, line))
                    {
                        if (fromChild.eof())
                            throw Leave();

                        break;
                    }
                    out << "Got: " << line << endl;
                }
            }
            catch (exception const &exc)
            {}
        }
    }
    catch (Leave)
    {}

    out << "The child returns value " << waitForChild() << endl;
}

