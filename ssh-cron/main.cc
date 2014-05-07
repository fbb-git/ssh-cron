#include <iostream>
#include <string>

#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/types.h>

#include <bobcat/pipe>
#include <bobcat/redirector>
#include <bobcat/ofdstream>
#include <bobcat/ifdstream>
#include <bobcat/process>
#include <bobcat/fork>
#include <bobcat/selector>

class ChildIO: public FBB::Fork
{
    enum Leave 
    {};

    FBB::Pipe childInput;   // child reads this
    FBB::Pipe childOutput;   // child writes this

    void childRedirections()    override;
    void childProcess()         override;
    void parentProcess()        override;
};

using namespace std;
using namespace FBB;


void ChildIO::childRedirections()
{
    childInput.readFrom(Redirector::STDIN);
    childOutput.writtenBy(Redirector::STDOUT);
}

void ChildIO::childProcess()
{
        // The /bin/cat program replaces the
        // child process started by Fork::fork()
    Process process(Process::DIRECT, "/usr/bin/ssh-agent /bin/bash");

// ssh-add works OK, but requires package ssh-askpass to be installed

    process.start();
   
    // this point is never reached
}

void ChildIO::parentProcess()
{
        // Set up the parent's sides of the pipes
    close(childOutput.writeFd());
    IFdStream fromChild(childOutput.readFd());

    close(childInput.readFd());
    OFdStream toChild(childInput.writeFd());

        // write lines to the child, read its output
    string line;

    Selector selector;
    selector.addReadFd(childOutput.readFd());

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

class Daemon: public FBB::Fork
{
    void childProcess() override;
    void parentProcess() override;
};

void Daemon::childProcess()
{
    prepareDaemon();
    ChildIO childIO;
    childIO.fork();

    cerr << "Daemon's child's parent process ends\n";
    throw 0;                
}

void Daemon::parentProcess()
{
}
    
int main()
try
{
    Daemon daemon;

    daemon.fork();

    return 0;
}
catch(exception const &exc)
{
    cerr << "Exception: " << exc.what() << endl;
}
catch(int x)
{
    cout << "The child terminates with: " << x << endl;
    return x;
}
