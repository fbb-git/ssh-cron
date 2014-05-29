#include "cronentry.ih"

void CronEntry::setEnvironment(size_t begin, size_t end, 
                          std::vector<std::string> const *environment)
{
    d_begin = begin;
    d_end = end;
    d_environment = environment;
}

