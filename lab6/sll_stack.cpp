#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Stack
{
    private:
        struct node
        {
            int data;
            struct node* next;
        };

        struct node* top;

    public:
        Stack()
        {
            top = NULL;
        }

        void push(int val);
        int pop();
        int peek();

};

int main() {

    Stack sll1;

    int loop = 1, ch = 0;

    while(loop)
    {
        int val;

        cout << "\n######## Stack ########\n";
        cout << "1.Push\n"
             << "2.Pop\n"
             << "3.Peek\n"
             << "4.Exit\n" << endl
             << "Enter your choice: ";
        cin  >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the value: ";
            cin  >> val;
            sll1.push(val);

            break;
        case 2:
            val = sll1.pop();
            if(val != -1) {
                cout << "The popped value is: " << val << endl;
            }

            break;
        case 3:
            val = sll1.peek();
            if (val != -1) {
                cout << "The top is '" << val << "'\n";
            }

            break;
        case 4:
            loop = 0;

            break;
        default:
            cout << "Invalid input!!!\n";

            break;
        }

        cout << "#######################\n";
    }
    return 0;
}

void Stack::push(int val)
{
    struct node* newnode = new struct node;
    newnode->data = val;

    newnode->next = top;
    top = newnode;
}

int Stack::pop()
{
    if (top == NULL) {
        cout << "The stack is empty\n";
        return -1;
    }

    int val = top->data;
    struct node* ftemp = top;
    top = top->next;
    free(ftemp);

    return val;
}

int Stack::peek()
{
    if (top == NULL) {
        cout << "The stack is empty\n";
        return -1;
    }

    return top->data;
}