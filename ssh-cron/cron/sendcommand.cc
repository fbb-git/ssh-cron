#include "cron.ih"

void Cron::sendCommand(string line)
{
    *d_toChild << line << endl;
}





