#include "cron.ih"

void Cron::sendCommand(string line)
{
    imsg << "Sending command `" << line << '\'' << endl;

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
            imsg << "Received: " << line << endl;
        }
    }
    catch (exception const &)
    {}
}


