#include "parser.ih"

Parser::Parser(istream &in, CronData &cronData)
:
    d_cronData(cronData),
    d_scanner(in)
{}
