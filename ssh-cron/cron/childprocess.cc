#include "cron.ih"

void Cron::childProcess()
{
    Process process(Process::DIRECT, s_agent);
    // ssh-add works OK, but requires package ssh-askpass to be installed

    process.start();

    // this point is never reached
    fmsg << "could not execute `" << s_agent << '\'' << endl;
}
