#include "parser.ih"

void Parser::error(char const *msg)
{
    emsg << msg << " at line " << d_cronData.lineNr() <<
             endl;
}

