#include "daemon.ih"

string Daemon::askPassPhrase()
{
    Tty tty;
    tty.echo(Tty::OFF);

    ifstream in;
    Exception::open(in, "/dev/tty");

    cout << "Enter passphrase: " << flush;
    string passphrase;
    getline(in, passphrase);

    cout << endl;

    return passphrase;
}
