#include <iostream>
#include <string>
#include "stack.h"

using std::cout, std::cin, std::endl;
using std::string;

bool check(string expr);

int main() {
    
    int loop = 1, ch = 0;
    while (loop) 
    {
        string expr = "\0";

        cout << "__________________________________________\n";
        cout << "1.Check Balance\n"
             << "2.Exit\n" << endl
             << "Enter your choice: ";
        cin  >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter your expression: ";
            cin  >> expr;
            if (check(expr)) {
                cout << "The expression " << expr << " is balanced\n";
            }
            else {
                cout << "The expression " << expr << " is not balanced\n";
            }

            break;
        case 2:
            loop = 0;
            cout << "EXITING...\n";

            break;
        default:
            break;
        }
        cout << "__________________________________________\n";
    }
    return 0;
}

bool check(string expr) {
    Stack stk;

    for (char ch : expr) {
        if (ch == '(') {
            stk.push(ch); 
        } else if (ch == ')') {
            if (stk.isempty()) {
                return false; 
            }
            stk.pop(); 
        }
    }
    if (stk.isempty()) {
        return true;
    }

    return false;
}