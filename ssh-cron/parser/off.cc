#include "parser.ih"

ostream &Parser::off(ostream &mstream)
{
    mstream << endl;
    dynamic_cast<Mstream &>(mstream).off();
    s_errors = true;

    return mstream;
}
