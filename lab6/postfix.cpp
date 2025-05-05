#include <iostream>
#include <cctype>
#include <string>
#include "stack.h"

using std::cout, std::cin, std::endl;
using std::string;

class Postfix
{
    private:
        string infix, postfix;

    public:
        Postfix()
        {
            infix = postfix = "";
        }

        void getinfix();
        void convertinfix();
        void evalpostfix();

};

int precedence(char op);

int main() {
    Postfix exp;

    cout << "\n############# RULE ###############\n";
    cout << "-> Cannot handle multi-digit\n";
    cout << "-> Example input: a=4+2*(3-5)";
    int loop = 1,ch = 0;
    while (loop)
    {
        cout << "\n######## INFIX TO POSTFIX ########\n";
        cout << "1. Get Infix\n";
        cout << "2. Convert Infix\n";
        cout << "3. Evaluate Postfix\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: 
                exp.getinfix(); 
                
                break;
            case 2: 
                exp.convertinfix(); 
                
                break;
            case 3: 
                exp.evalpostfix();
                
                break;
            case 4: 
                cout << "Exiting program.\n"; 
                loop = 0;

                break;
            default: 
                cout << "Invalid choice! Try again.\n";

                break;
        }

        cout << "##################################\n";
    }
    
    return 0;
}

int precedence(char op)
{
    if(op == '=')                            return 0;
    if(op == '+' || op == '-')               return 1;
    if(op == '*' || op == '/' || op == '%')  return 2;
    return -1;
}


void Postfix::getinfix()
{
    cout << "Enter your infix expression: ";
    cin  >> infix;

    cout << "\nYour expression is:\n" << infix << endl;
}

void Postfix::convertinfix()
{
    if (infix.empty()) {
        cout << "Provide a infix expression.\n";
        return;
    }

    Stack opr;
    postfix = "";
    int brac_check = 1;
    for(char ch : infix)
    {
        if (isdigit(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            brac_check = 0;

            opr.push(ch);
        }
        else if (ch == ')') {
            brac_check = 1;
            while (opr.peek() != '(')
            {
                if (opr.isempty()) {
                    cout << "Invalid expression!!!\n";
                    return;
                }

                postfix += opr.pop();
            }
            opr.pop();
        }
        else if (!isalpha(ch)) {
            while (!opr.isempty() && precedence(opr.peek()) >= precedence(ch)) 
            {
                postfix += opr.pop();
            }
            opr.push(ch);
        }
    }

    while (!opr.isempty()) 
    {
        postfix += opr.pop();
    }

    cout << "Your Postfix expression is:\n" << postfix << endl;
}

void Postfix::evalpostfix()
{
    if (postfix.empty()) {
        cout << "No postfix expression found! Convert infix first.\n";
        return;
    }

    bool isAssigned = false;
    Stack opr;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            opr.push(ch - '0');
        }
        else if (ch == '=') {
            isAssigned = true;
        }
        else {
            int val2 = opr.pop();
            int val1 = opr.pop();
            switch (ch) {
                case '+': 
                    opr.push(val1 + val2); 
                    break;
                case '-': 
                    opr.push(val1 - val2); 
                    break;
                case '*': 
                    opr.push(val1 * val2); 
                    break;
                case '%':
                    opr.push(val1 % val2); 
                    break;
                case '/': 
                    if (val2 == 0) {
                        cout << "Error: Division by zero!\n";
                        return;
                    }
                    opr.push(val1 / val2); 
                    break;
            }
        }
    }

    int result = opr.pop();
    if (isAssigned) {
        cout << "The result of the assignment: " << result << endl;
    } else {
        cout << "The result: " << result << endl;
    }
}
