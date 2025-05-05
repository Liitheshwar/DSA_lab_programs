#include <iostream>
#include "Stack.h"

void processString(std::string input) {
    Stack stack;
    
    for (char ch : input) {
        if (ch == '+') {
            stack.pop();
        } else {
            stack.push(ch);
        }
    }

    std::string result = "";
    while (!stack.isempty()) {
        result = stack.pop() + result;
    }

    std::cout << result << std::endl;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;
    processString(input);
    return 0;
}
