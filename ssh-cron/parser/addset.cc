#include "parser.ih"

void Parser::addSet(set<int> &lhs, set<int> const &rhs) const
{
    lhs.insert(rhs.begin(), rhs.end());
}
