#include "main.ih"

int main()
try
{
    Daemon daemon;
    daemon.fork();
}
catch(exception const &exc)
{
    cerr << "Exception: " << exc.what() << endl;
}
catch(int x)
{
    cout << "The child terminates with: " << x << endl;
    return x;
}
