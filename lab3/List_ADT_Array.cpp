//PRogram to give a menu driven program to create a List ADT using array of size 5 and create function for it 
#include <iostream>
#define SIZE 5

//List ADT class
class array
{
    private:
        int arr[SIZE];
        int current;

    public:
        array() {
            for (int i = 0; i < SIZE; i++) {
                arr[i] = 0;
            }
            current = -1;
        }

        void insert_beg(int val);
        void insert_end(int val);
        void insert_pos(int val, int pos);
        int delete_beg();
        int delete_end();
        int delete_pos(int pos);
        int search(int val);
        void rotate(int step);
        void display();

        //reverse the array and used in rotate function
        void reverse(int start, int end);
};

int main() {
    array list;
    
    //Menu given to user to work on the List ADT
    int ch = 0;
    int check = 1;
    int loop = 1;
    while(loop)
    {
        std::cout << "############ LIST ADT ############\n" << std::endl;

        std::cout << "1.Insert Beginning\n"
                  << "2.Insert End\n"
                  << "3.Insert Position\n"
                  << "4.Delete Beginning\n"
                  << "5.Delete End\n"
                  << "6.Delete Position\n"
                  << "7.Search\n"
                  << "8.Display\n"
                  << "9.Rotate\n"
                  << "10.Exit\n" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> ch;

        int val =0;
        int pos = -1;
        switch (ch)
        {
        case 1:
            std::cout << "\nEnter the value to insert: ";
            std::cin >> val;
            list.insert_beg(val); 
            break;
        
        case 2:
            std::cout << "\nEnter the value to insert: ";
            std::cin >> val;
            list.insert_end(val);
            break;

        case 3:
            std::cout << "\nEnter the value to insert: ";
            std::cin >> val;
            std::cout << "\nEnter position to insert: ";
            std::cin >> pos;
            list.insert_pos(val,pos);  
            break;

        case 4:
            val = list.delete_beg();
            if (val != -1) {
            std::cout << "The item deleted is: " << val << std::endl;
            }
            break;

        case 5:
            val = list.delete_end();
            if (val != -1) {
            std::cout << "The item deleted is: " << val << std::endl;
            }
            break;

        case 6:
            std::cout << "\nEnter the position to delete item: ";
            std::cin >> pos;
            val = list.delete_pos(pos);
            if (val != -1) {
            std::cout << "The item deleted is: " << val << std::endl;
            }
            break;

        case 7:
            std::cout << "\nEnter the item to find: ";
            std::cin >> val;
            pos = list.search(val);

            if (pos == -1) {
                std::cout << "\nThe item is no in list!!\n";
            }
            else {
                std::cout << "\nThe item is at position: " << pos << std::endl;
            }
            break;

        case 8:
            list.display();
            break;

        case 9:
            std::cout << "\nEnter the steps to rotate: ";
            std::cin >> val;
            list.rotate(val);
            break;

        case 10:
            loop = 0;
            break;
        
        default:
            std::cout << "Invalid input!!!\n" << std::endl; 
            break;
        }

        std::cout << "##################################\n" << std::endl;
    }

    return 0;
}


//INSERT functions of List ADT
void array::insert_beg(int val)
{
    if (current == 4) { 
        std::cout << "The array is full!" << std::endl;
        return;
    }
    
    if (current == -1) {
        arr[0] = val;
        current = 0;
        return;
    }

    for (int i = current; i >= 0; i--) {
        arr[i+1] = arr[i];
    }
    
    arr[0] = val;
    current++;
}

void array::insert_end(int val)
{
    if (current == 4) { 
        std::cout << "The array is full!" << std::endl;
        return;
    }

    if (current == -1) {
        insert_beg(val);
        return;
    }

    arr[current+1] = val;
    current++;
}

void array::insert_pos(int val, int pos)
{
    if (current == 4) { 
        std::cout << "The array is full!" << std::endl;
        return;
    }
    if (pos > current) {
        std::cout << "The position is greater than the list!!!" << std::endl;
        return;
    }
    if (pos < 0) {
        std::cout << "The position is less than 0!!!" << std::endl;
    }
    if (pos == 0) {
        insert_beg(val);
        return;
    }
    if (pos == current+1) {
        insert_end(val);
        return;
    }
    

    for (int i = current; i >= pos; i--) {
        arr[i+1] = arr[i];
    }

    arr[pos] = val;
    current++;
}


//DELETE functions of List ADT
int array::delete_beg()
{
    if (current == -1) {
        std::cout << "The list is empty!" << std::endl;
        return -1;
    }

    int pop = arr[0];

    for (int i = 0; i < current; i++) {
        arr[i] = arr[i+1];
    }

    current--;
    return pop;
}

int array::delete_end()
{
    if (current == -1) {
        std::cout << "The list is empty!!!\n";
        return -1;
    }

    int pop = arr[current];
    current--;
    return pop;
   
}

int array::delete_pos(int pos)
{
    if (current == -1) {
        std::cout << "The list is empty!!!\n";
        return -1;
    }

    if (pos > current) {
        std::cout << "The position exedes the list\n";
        return -1;    
    }
    if (pos < 0) {
        std::cout << "The position is less than 0!!!" << std::endl;
    }

    int pop = arr[pos];
    for (pos; pos < current; pos++)
    {
        arr[pos] = arr[pos+1];
    }
    current--;
    return pop;
}


//SEARCH function of List ADT
int array::search(int val)
{
    for (int i = 0; i < current+1; i++)
    {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1;
}


//DISPLAY function of List ADT
void array::display()
{
    if (current == -1) {
        std::cout << "The array is empty!" << std::endl;
        return;
    }
    
    std::cout << "Array contents: ";
    for (int i = 0; i <= current; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


//ROTATE function of List ADT
void array::rotate(int step)
{
    if (step == 0) {
        return;
    }
    if (step < 0) {
        std::cout << "The step count is less than 0!!!" << std::endl;
    }


    step = step-1;
    reverse(0,current);
    reverse(0,step);
    reverse(step+1,current);
}

void array::reverse(int start, int end)  // REVESE function used to reverse the items in the array
{
    int temp = 0;
    for (int i = start; i < (current+end+1)/2; i++)
    {
        temp = arr[end];
        arr[end] = arr[i];
        arr[i] = temp;
        end--; 
    }
    
}