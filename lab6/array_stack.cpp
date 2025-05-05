#include <iostream>

#define LEN 50

using std::cout;
using std::cin;
using std::endl;

class Stack 
{
    private:
        int arr[LEN];
        int top;

    public:
        Stack()
        {
            top = -1;
        }

        void push(int val);
        int pop();
        int peek();
};

int main() {

    Stack arr1;

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
            arr1.push(val);

            break;
        case 2:
            val = arr1.pop();
            if(val != -1) {
                cout << "The popped value is: " << val << endl;
            }

            break;
        case 3:
            val = arr1.peek();
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
    if (top == LEN) {
        cout << "Stack limit reached.\n";
        return;
    }

    top++;
    arr[top] = val;
}

int Stack::pop()
{
    if (top == -1) {
        cout << "The stack is empty\n";
        return -1;
    }

    int pop = arr[top];
    top--;
    return pop;
}

int Stack::peek()
{
    if (top == -1) {
        cout << "The stack is empty\n";
        return -1;
    }

    return arr[top];
}