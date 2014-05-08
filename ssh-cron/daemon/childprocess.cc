#include "daemon.ih"

void Daemon::childProcess()
{
    prepareDaemon();

    ChildIO childIO;
    childIO.fork();

    // to be logged:  "Daemon's child's parent process ends\n";

    throw 0;                    // correctly end the child process at main
}
