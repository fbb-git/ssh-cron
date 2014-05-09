#include "scanner.ih"

void Scanner::getTail()
{
    begin(StartCondition__::tail);

    d_returnCommand = true;
}
