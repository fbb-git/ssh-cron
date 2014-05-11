#include "parser.ih"

Parser::Parser(Options &options, CronData &cronData)
:
    d_options(options),
    d_cronData(cronData),
    d_scanner(ArgConfig::instance()[0], "-")
{}
