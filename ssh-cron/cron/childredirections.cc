#include "cron.ih"

void Cron::childRedirections()
{
    d_childInput.readFrom(STDIN_FILENO);

    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    open("/dev/null", O_WRONLY);        // reopen cout
    open("/dev/null", O_WRONLY);        // reopen cerr

}
