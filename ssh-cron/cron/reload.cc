#include "cron.ih"

void Cron::reload(istream &sharedIn)
{
    string path;
    getline(sharedIn, path);
    imsg << "daemon: RELOAD " << path << endl;

    d_cronData = CronData();
    d_cronData.messages(false);
    
    ifstream in;
    Exception::open(in, path);

    Parser parser(in, d_cronData);

    parser.parse();
}
