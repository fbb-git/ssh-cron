//                     usage.cc

#include "main.ih"

void usage(std::string const &progname)
{
    cout << "\n" <<
    progname << " by " << Icmbuild::author << "\n" <<
    progname << " V" << Icmbuild::version << " " << Icmbuild::years << "\n"
    "\n"
    "Usage: " << progname << " [options] args\n"
    "Where:\n"
    "   [options] - optional arguments (short options between parentheses):\n"
    "      --help (-h)      - provide this help\n"
    "      --no-daemon      - do not run as a daemon\n"
    "      --pid-file (-p) path - `path' is the path name of the file "
                                                                "containing\n"
    "                            the daemon's PID\n"
    "                           (default `" <<
                                        Options::defaultPIDfile() << "')\n"
    "      --verbose          - write additional information:\n"
    "                               with --no-daemon: to stdout;\n"
    "                               with daemons and --no-syslog not "
                                                                "specified:\n"
    "                                                 to the syslog daemon\n"
    "      --version (-v)   - show version information and terminate\n"
    "   args   - explain additional arguments.\n"
    "\n";
}
