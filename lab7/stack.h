#ifndef STACK_H
#define STACK_H

# include <iostream>

class Stack
{
    private:
        struct node
        {
            char data;
            struct node* next;
        };

        struct node* top;

    public:
        Stack()
        {
            top = NULL;
        }

        int isempty();
        void push(int val);
        char pop();
        char peek();

};

int Stack::isempty() {return top == NULL;}

void Stack::push(int val)
{
    struct node* newnode = new struct node;
    newnode->data = val;

    newnode->next = top;
    top = newnode;
}

char Stack::pop()
{
    if (isempty()) {
        return '\0';
    }

    int val = top->data;
    struct node* ftemp = top;
    top = top->next;
    free(ftemp);

    return val;
}

char Stack::peek()
{
    if (isempty()) {
        return '\0';
    }

    return top->data;
}

#endif