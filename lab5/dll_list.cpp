//List ADT using doubly linked list
#include <iostream>
#include <stdlib.h>

#define NEWNODE (struct node*)malloc(sizeof(struct node)) 

using namespace std;

class List
{
    private:
        struct node
        {
            struct node* prev;
            int data;
            struct node* next;
        };

        struct node* head;
        struct node* tail;

    public:
        List();
        
        void insert_beg(int val);
        void insert_end(int val);
        void insert_pos(int val, int pos);

        void display();
};

int main() {

    List l1;
    int ch,val = 10,pos = 0;
    int loop = 1;

    while (loop) {
        cout << "###################### LIST ADT ######################\n";

        cout << "\n1.Insert Beginning\n"
                  << "2.Insert End\n"
                  << "3.Insert Position\n"
                  << "4.Delete Beginning\n"
                  << "5.Delete End\n"
                  << "6.Delete Position\n"
                  << "7.Search\n"
                  << "8.Display\n"
                  << "9.Exit\n" << std::endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> val;
            l1.insert_beg(val);

            break;

        case 2:
            cout << "Enter the value: ";
            cin >> val;
            l1.insert_end(val);

            break;

        case 3:
            cout << "Enter the value: ";
            cin >> val;
            cout << "Enter the index: ";
            cin >> pos;
            l1.insert_pos(val,pos);

            break;

        case 4:
            
            break;

        case 5:

            break;

        case 6:

            break;

        case 7:
           
            break;

        case 8:
            l1.display();

            break;

        case 9:
            cout << "EXITING...\n";
            loop = 0;
            break;

        default:
            break;
        }

        cout << "######################################################\n" << endl;
    }

    return 0;
}


List::List()
{
    head = NULL;
    tail = NULL;
}

void List::insert_beg(int val)
{
    struct node* newnode = NEWNODE;
    newnode->data = val;
    newnode->prev = NULL;

    if (head == NULL) {
        head = newnode;
        tail = newnode;
        newnode->next = NULL;

        return;
    }

    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void List::insert_end(int val)
{
    struct node* newnode = NEWNODE;
    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        tail = newnode;
        newnode->prev = NULL;

        return;
    }

    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
}

void List::insert_pos(int val, int pos)
{
    if (pos == 0) {
        insert_beg(val);
        return;
    }

    int check = -1;
    struct node* temp = head;

    pos--;
    while(check != pos)
    {
        if (temp->next == NULL) {
            if (check == (pos-1)) {
                insert_end(val);
                return;
            }

            cout << "The index is greater than the list\n";
            return;
        }

        temp = temp->next;
        check++;
    }

    struct node* newnode = NEWNODE;
    newnode->data = val;
    newnode->prev = temp;
    newnode->next = temp->next;

    temp->next->prev = newnode;
    temp->next = newnode;
}
void List::display()
{
    if (head == NULL) {
        cout << "\nThe List is empty" << endl;
        return;
    }

    struct node* temp;
    temp = head;
    cout << "The List content in forward: ";
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    temp = tail;
    cout << "\nThe List content in reverse: ";
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}