#include "cron.ih"

void Cron::childRedirections()
{
    d_childInput.readFrom(STDIN_FILENO);
    d_childOutput.writtenBy(STDOUT_FILENO);
}
