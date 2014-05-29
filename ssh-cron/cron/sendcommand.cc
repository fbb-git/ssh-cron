#include "cron.ih"

void Cron::sendCommand(string line)
{
    imsg << "command: " << line << '\n';
    *d_toChild << line << endl;
}





