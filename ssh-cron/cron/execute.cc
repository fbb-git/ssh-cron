#include "cron.ih"

void Cron::execute(CronEntry const &entry)
{
    string command("(");

    for (size_t idx = 0, end = entry.nSettings(); idx != end; ++idx)
        command += d_cronData.environment()[idx] + ';';

    command += "_run_ " + entry.command() + ")&";

    d_options.msg() << entry.command() << endl;

    sendCommand(command);
}
