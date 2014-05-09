#include "parser.ih"

void Parser::error(char const *msg)
{
    emsg << "Syntax error in cron-command at line " << d_scanner.lineNr() <<
             off;
}

