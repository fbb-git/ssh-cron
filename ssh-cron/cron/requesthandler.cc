#include "cron.ih"

void Cron::requestHandler(Cron *cronPtr)
{
    cronPtr->handleRequests();
}
