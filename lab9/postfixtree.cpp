#include <iostream>
#include <stack>
#include "binarytree.h"

std::string get_postfix();
bool check_postfix(std::string postfix);

int main() {
    BinaryTree tree;

    int loop = 1, ch = 0;
    std::string postfix = "\0";

    while (loop) {
        std::cout << "\n####### Expression Tree #######\n";
        std::cout << "1. Postfix\n"
             << "2. Construct Tree \n"
             << "3. Inoreder\n"
             << "4. Preorder \n"
             << "5. Postorder \n"
             << "6. Exit\n"
             << "Enter your choice: ";
        std::cin >> ch;

        switch (ch) {
            case 1:
                postfix = get_postfix();
                break;

            case 2:
                tree.construct(postfix);
                break;

            case 3:
                std::cout << "Inorder : ";
                tree.inorder();
                break;

            case 4:
                std::cout << "Preorder : ";
                tree.preorder();
                break;

            case 5:
                std::cout << "Postorder : ";
                tree.postorder();
                break;

            case 6:
                loop = 0;
                break;

            default:
                std::cout << "Invalid input!!!\n";
                break;
        }
        std::cout << "###############################\n";
    }

    return 0;
}

std::string get_postfix()
{
    std::string postfix;
    std::cout << "Enter a postfix expression: ";
    std::cin >> postfix;

    return postfix;
}

