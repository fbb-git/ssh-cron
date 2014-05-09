#include "parser.ih"

void Parser::defineRange(set<int> &lhs, set<int> const &rhs) const
{
    int begin = *lhs.begin();
    int end = *rhs.begin();

    if (begin > end)
    {
        emsg << "Line " << d_scanner.lineNr() << ": invalid range " << 
                 begin << '-' << end << off;
        return;
    }
        
    for (++begin, ++end; begin != end; ++begin)
        lhs.insert(begin);
}
