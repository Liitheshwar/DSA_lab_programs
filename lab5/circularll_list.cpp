#include <iostream>
#include <cstdlib>

using namespace std;


class List {

    struct node {
        int data;
        struct node* next;
    };

    struct node* head;

    public:
    List();

    void insert_beg(int val);
    void insert_end(int val);
    void insert_pos(int val, int pos);
    int delete_beg();
    int delete_end();
    int delete_pos(int pos);
    int search(int val);
    void display();
};

int main(){

    List l1;
    int ch,val = 10,pos = 0;
    int loop = 1;

    while (loop) {
        std::cout << "######################## LIST ADT ########################\n" << std::endl;
        std::cout << "1.Insert Beginning\n"
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
            cout << "Enter a value: ";
            cin >> val;
            l1.insert_beg(val);

            break;
        case 2:
            cout << "Enter a value: ";
            cin >> val;
            l1.insert_end(val);

            break;
        case 3:
            cout << "Enter a value: ";
            cin >> val;
            cout << "Enter the index: ";
            cin >> pos;
            l1.insert_pos(val,pos);

            break;

        case 4:
            val = l1.delete_beg();
            if (val != -1) {
                cout << "The value deleted is: " << val << endl;
            }
            
            break;

        case 5:
            val = l1.delete_end();
            if (val != -1) {
                cout << "The value deleted is: " << val << endl;
            }

            break;

        case 6:
            cout << "Enter the index to delete: ";
            cin >> pos;

            val = l1.delete_pos(pos);
            if (val != -1) {
                cout << "The value deleted is: " << val << endl;
            }

            break;

        case 7:
            cout << "ENter the value to search: ";
            cin >> val;

            pos = l1.search(val);
            if (val != -1) {
                cout << "The value is found at index " << pos << endl;
            }
            
            break;

        case 8:
            l1.display();
            break;

        case 9:
            loop = 0;
            break;

        default:
            break;
        }

        std::cout << "##########################################################\n" << std::endl;
    }

    return 0;
}

List::List()
{
    head = NULL;
}

void List::insert_beg(int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;

    if (head == NULL) {

        newnode->next = newnode;
        head = newnode;
    }
    else {

        newnode->next = head;

        struct node *temp;
        temp = head;
        while(temp->next != head) 
        {
            temp = temp->next;
        }
        head = newnode;
        temp->next = head;

    }
}

void List::insert_end(int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;

    if (head == NULL) {

        newnode->next = newnode;
        head = newnode;
    }
    else {

        struct node* temp = head;
        while(temp->next != head) 
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
    }
}


void List::insert_pos(int val, int pos)
{
    if (head == NULL && pos == 0) {
        insert_beg(val);
        return;
    }

    if (head == NULL) {
        cout << "The list is empty and the index is greater than list!!!\n";
    }

    struct node* temp = head;
    int check = 0;
    for (int i = 0; i < pos-1; i++)
    {
        if (temp->next == head && pos-1 > check-1) {
            cout << "The index is greater than list!!\n";
            return;
        }

        temp = temp->next;
        check++;
    }

    if (temp->next == head) {
        insert_end(val);
        return;
    }

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;

    newnode->next = temp->next;
    temp->next = newnode;
}


int List::delete_beg()
{
    int pop;
    if (head == NULL) {
        cout << "The list is empty!!!\n";
        return -1;
    }

    if (head->next == head) {
        pop = head->data;
        free(head);
        head = NULL;
        return pop;
    }

    struct node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    pop = head->data;
    head = head-> next;
    free(temp->next);
    temp->next = head;
    
    return pop;

}

int List::delete_end()
{
    if (head == NULL) {
        cout << "The list is empty!!!\n";
        return -1;
    }

    int pop;
    if (head->next == head) {
        return delete_beg();
    }

    struct node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }

    struct node* ftemp = temp->next;
    pop = ftemp->data;
    temp->next = head;

    free(ftemp);
    return pop;

}

int List::delete_pos(int pos)
{
    if (head == NULL) {
        cout << "The list is empty!!!\n";
        return -1;
    }

    if (pos == 0) {
        return delete_beg();
    }

    int check = 0;
    struct node* temp = head;

    while (temp->next != head && check < pos - 1) {
        temp = temp->next;
        check++;
    }

    if (check != pos - 1 || temp->next == head) {
        cout << "The index is greater than the list size!!\n";
        return -1;
    }

    struct node* ftemp = temp->next;
    int pop = ftemp->data;
    temp->next = ftemp->next;

    free(ftemp);
    return pop;
}


int List::search(int val)
{
    if (head == NULL) {
        cout << "The List is empty!!!\n";
        return -1;
    }

    struct node *temp = head;
    int idx = 0;

    do {
        if (temp->data == val) {
            return idx;
        }
        idx++;
        temp = temp->next;
    } while (temp != head);

    cout << "The value is not in List!!\n";
    return -1;
}



void List::display()
{
    cout << "\nList contents: ";

    if(head == NULL) {
        cout << "The List is empty!!!\n";
    }
    else {
        struct node *temp;

        temp = head;

        while(temp->next != head) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
}