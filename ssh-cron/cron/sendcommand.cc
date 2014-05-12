#include "cron.ih"

void Cron::sendCommand(string line)
{
    if (not d_sendCommands)
        return;

    d_log << "Sending command `" << line << '\'' << endl;

    *d_toChild << line << endl;

    d_selector.setAlarm(0, 300000);
    try
    {
        while (d_selector.wait() > 0)
        {
            if (not getline(*d_fromChild, line))
            {
                if (d_fromChild->eof())
                    throw Leave();

                break;
            }
            d_log << "Received: " << line << endl;
        }
    }
    catch (exception const &)
    {}
}


