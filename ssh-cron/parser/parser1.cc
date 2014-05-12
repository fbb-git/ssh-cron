#include "parser.ih"

Parser::Parser(CronData &cronData)
:
    d_cronData(cronData),
    d_scanner(ArgConfig::instance()[0], "-")
{}
