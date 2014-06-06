#include "crondata.ih"

void CronData::setEnvVar(string const &var, string const &value)
{
    if (not value.empty())
    {
        d_environment.push_back(var + '=' + String::trim(value));
        if (d_info)
            imsg << Options::instance().basename() << ": envvar " << 
                    d_environment.size() << " `" << d_environment.back() << 
                    '\'' << endl;
    }
}
