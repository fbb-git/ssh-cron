#include "daemon.ih"

ostream &Daemon::basename() const
{
    return d_options.msg() << d_options.basename() << ": ";
}
