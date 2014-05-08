#include "cron.ih"

void Cron::childProcess()
{
    string command = s_agent + ' ' + s_shell;

    Process process(Process::DIRECT, command);
    // ssh-add works OK, but requires package ssh-askpass to be installed

    process.start();
    // this point is never reached
}
