#include <iostream>
#include "scanner.h"

using namespace std;

int main()
{
    Scanner scanner;

    while (int value = scanner.lex())
    {
        cout << "token: ";
        if (value < 1000) 
            cout << static_cast<char>(value);
        else
            cout << value;

        cout << ", matched: " << scanner.matched() << '\n';
    }
}
