#include "parser.ih"

set<int> Parser::acceptNr() const
{
    set<int> ret;

    int nr = stol(d_scanner.matched());

    if (nr >= 0 && nr < 60)
        ret.insert(nr);
    else 
        emsg << "Line " << d_scanner.lineNr() << ": nr " << nr << 
                " out of range" << off;

    return ret;
}
