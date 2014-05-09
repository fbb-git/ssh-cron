#include "scanner.ih"

void Scanner::checkOption()
{
    more();
    begin(StartCondition__::tail);

    // if matched() is an option, set returnCommand to false
    d_returnCommand = true;
}
