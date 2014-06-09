#include "cron.ih"

bool Cron::reload(istream &sharedIn)
{
    string passPhrase;
    getline(sharedIn, passPhrase);

    if (hmac(passPhrase) != d_passPhrase)
        return false;

    string path;
    getline(sharedIn, path);
    idmsg() << "reloading from " << path << endl;

    d_cronData = CronData();

    d_cronData.messages(false);
    
    ifstream in;
    Exception::open(in, path);

    Parser parser(in, d_cronData);

    parser.parse();

    return true;
}











