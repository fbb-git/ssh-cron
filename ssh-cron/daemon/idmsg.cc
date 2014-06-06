#include "daemon.ih"

ostream &Daemon::idmsg() const
{
    return imsg << d_options.basename() << ": ";
}
