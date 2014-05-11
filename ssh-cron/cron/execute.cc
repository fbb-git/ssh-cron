#include "cron.ih"

void Cron::execute(CronEntry const &entry)
{
    string command("(");

    for (size_t idx = 0, end = entry.nSettings(); idx != end; ++idx)
        command += d_cronData.environment()[idx] + ';';

    command += entry.command() + ")&";

    imsg << command << '\n';
}
