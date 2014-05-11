#include "crondata.ih"

void CronData::setEnvVar(string const &var, string const &value)
{
    if (not value.empty())
    {
        d_environment.push_back(var + '=' + String::trim(value));
        imsg << "Envvar " << d_environment.size() << ": " <<
                d_environment.back() << endl;
    }
}
