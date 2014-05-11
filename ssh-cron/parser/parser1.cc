#include "parser.ih"

Parser::Parser(CronData &cronData)
:
    d_scanner(ArgConfig::instance()[0], "-"),
    d_cronData(cronData)
{
}
