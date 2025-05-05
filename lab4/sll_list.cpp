#include <iostream>
#include <stdlib.h>

class List
{
    private:
        struct node
        {
            int data;
            struct node* next;
        };

        struct node* head;

    public:
        List()
        {
            head = NULL;
        }

        void insert_beg(int val);
        void insert_end(int val);
        void insert_pos(int val, int pos);
        int delete_beg();
        int delete_end();
        int delete_pos(int pos);
        int search(int val);
        void display();
        void display_rev();
        void reverse_link();
        
        void reverse_reccur(struct node* temp);

};


int main() {

    List sl1;

    int loop = 1;
    while(loop)
    {
        int ch = 0;
        std::cout << "\n################ LIST ADT ################\n" << std::endl;

        std::cout << "1.Insert Beginning\n"
                  << "2.Insert End\n"
                  << "3.Insert Position\n"
                  << "4.Delete Beginning\n"
                  << "5.Delete End\n"
                  << "6.Delete Position\n"
                  << "7.Serach\n"
                  << "8.Display\n"
                  << "9.Reverse Display\n"
                  << "10.Reverse Link\n"
                  << "11.Exit\n" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> ch;

        int val =0;
        int pos = -1;
        switch (ch)
        {
        case 1:
            std::cout << "Enter the value: ";
            std::cin >> val;
            sl1.insert_beg(val);

            break;
        
        case 2:
            std::cout << "Enter the value: ";
            std::cin >> val;
            sl1.insert_end(val);

            break;

        case 3:
            std::cout << "Enter the value: ";
            std::cin >> val;
            std::cout << "Enter the index: ";
            std::cin >> pos;
            sl1.insert_pos(val,pos);

            break;

        case 4:
            val = sl1.delete_beg();
            if (val != -1) {
                std::cout << "The deleted value is: " << val << std::endl;
            }

            break;

        case 5:
            val = sl1.delete_end();
            if (val != -1) {
                std::cout << "The deleted value is: " << val << std::endl;
            }

            break;

        case 6:
            std::cout << "Enter the index: ";
            std::cin >> pos;

            val = sl1.delete_pos(pos);
            if (val != -1) {
                std::cout << "The deleted value is: " << val << std::endl;
            }
            break;

        case 7:
            std::cout << "Enter the value to search: ";
            std::cin >> val;
            
            pos = sl1.search(val);
            if (pos == -1) 
                std::cout << "The element is not present in the List!!\n";
            else 
                std::cout << "The element is present at index: " << pos << std::endl;

            break;

        case 8:
            sl1.display();

            break;

        case 9:
            sl1.display_rev();

            break;

        case 10:
            sl1.reverse_link();
            
            break;

        case 11:
            loop = 0;
            break;
        
        default:
            std::cout << "Invalid input!!!\n" << std::endl; 
            break;
        }

        std::cout << "##########################################\n" << std::endl;
    }

    return 0;
}

void List::insert_beg(int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;

    newnode->next = head;
    head = newnode;
}

void List::insert_end(int val)
{
    if (head == NULL) {
        insert_beg(val);
        return;
    }

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;

    struct node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    newnode->next = NULL;
    temp->next = newnode;
}

void List::insert_pos(int val, int pos)
{
    int check = 0;

    if (pos == 0) {
        insert_beg(val);
        return;
    }

    pos--;
    struct node* temp = head;
    while (check != pos)
    {
        if (temp->next == NULL) {
            if (check == pos) {
                insert_end(val);
                return;
            }
            else {
                std::cout << "The index is greater than the list!!\n";
                return;
            }
        }

        check++;
        temp = temp->next;
    }

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;

    newnode->next = temp->next;
    temp->next = newnode;

}


int List::delete_beg()
{
    if (head == NULL) {
        std::cout << "The list is empty!!\n";
        return -1;
    }

    struct node* temp = head;
    int pop_val = head->data;
    head = head->next;

    free(temp);
    return pop_val;
}

int List::delete_end()
{
    if (head == NULL) {
        std::cout << "The list is empty!!\n";
        return -1;
    }

    int pop_val;

    if (head->next == NULL) {
        pop_val = head->data;
        
        free(head);
        head = NULL;
        return pop_val;
    }
    struct node* temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    pop_val = temp->next->data;

    free(temp->next);
    temp->next = NULL;
    return pop_val;
}

int List::delete_pos(int pos)
{
    if (head == NULL) {
        std::cout << "The list is empty!!\n";
        return -1;
    }

    int pop_val;
    int check = 0;

    if (pos == 0) {
        pop_val = delete_beg();
        return pop_val;

    }

    pos--;
    struct node* temp = head;
    while (check != pos)
    {
        if (temp->next->next == NULL) {
            if (check == pos-1) {
                pop_val = delete_end();
                return pop_val;
            }
            else {
                std::cout << "The index is greater than the list!!\n";
                return -1;
            }
        }

        check++;
        temp = temp->next;
    }

    struct node* ftemp = temp->next;
    pop_val = ftemp->data;
    temp->next = ftemp->next;

    free(ftemp);
    return pop_val;
}


int List::search(int val)
{
    if (head == NULL) {
        std::cout << "The List is empty!!!\n";
    }

    struct node* temp = head;
    int idx = 0;

    if (head->data == val) {
        return idx;
    }

    while(temp->next != NULL)
    {
        if (temp->data == val) {
            return idx;
        }

        temp = temp->next;
        idx++;
    }

    return -1;
}


void List::display()
{
    std::cout << "The List contents: ";

    if (head == NULL) {
        std::cout << "The List is empty.\n";
        return;
    }

    struct node* temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void List::display_rev()
{
    std::cout << "The List contents in reverse: ";

    if (head == NULL) {
        std::cout << "The List is empty.\n";
        return;
    }

    reverse_reccur(head);
    std::cout << std::endl;

}
void List::reverse_reccur(struct node* temp)
{
    if(temp == NULL) {
        return;
    }

    reverse_reccur(temp->next);
    std::cout << temp->data << " ";
}


void List::reverse_link()
{
    if (head == NULL) {
        std::cout << "The list is empty, nothing to reverse.\n";
        return;
    }

    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    std::cout << "The list has been reversed.\n";
}