#include <iostream>
#include <cstdlib>

class List {

    struct node {
        int data;
        struct node* next;
    };

    struct node* head;

    public:
        List()
        {
            head = NULL;
        }

        void insertprocess(int val);
        void execute(int ftime);
        void display();

};

void List::insertprocess(int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;

    if (head == NULL) {
        newnode->next = newnode;
        head = newnode;
        return;
    }

    struct node* temp = head;
    while(temp->next != head) 
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = head;

}

void List::execute(int ftime)
{
    if (head == NULL) {
        std::cout << "The queue doesn't have anything to execute\n";
        return;
    }

    struct node* temp = head;
    int remaining_time = temp->data - ftime;

    if (remaining_time > 0) {
        temp->data = remaining_time;
        head = head->next;  // move to next process
    } else {
        std::cout << temp->data << std::endl;

        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            struct node* prev = head;
            while (prev->next != head) {
                prev = prev->next;
            }

            prev->next = head->next;
            struct node* to_delete = head;
            head = head->next;
            free(to_delete);
        }
    }
}



void List::display()
{
    if(head == NULL) {
        std::cout << "The Queue is empty!!!\n";
    }
    else {
        struct node *temp;

        temp = head;

        while(temp->next != head) 
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << temp->data << std::endl;
    }
}