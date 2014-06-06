#include "cron.ih"

void Cron::execute(CronEntry const &entry)
{
    string command("(");

    for (size_t idx = 0, end = entry.nSettings(); idx != end; ++idx)
        command += d_cronData.environment()[idx] + ';';

    command += "_run_ " + entry.command() + ")&";

    scheduler() << entry.command() << endl;
    idmsg() << "executed as " << command << endl;
    sendCommand(command);
}
