#include "cron.ih"

void Cron::setPassPhrase(string const &passPhrase)
{
    d_passPhrase = hmac(passPhrase);
}
