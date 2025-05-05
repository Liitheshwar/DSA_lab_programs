#include <iostream>
#include <list>
#include <vector>

#define SIZE 10
#define EMPTY -1

using namespace std;

class HashTable 
{
    private:
        vector< list<int> > table;

        int hash(int key)
        {
            return key % SIZE;
        }

    public:
        HashTable()
        {
            for (int i = 0; i < SIZE; i++) 
            {
                list<int> head;
                head.push_back(EMPTY);

                table.push_back(head);
            }
        }

        void insert(int key);
        void remove(int key);
        int search(int key);
        void display();
};

int main() {
    HashTable ht;

    int key = 0, loop = 1, ch = 0;

    while(loop) 
    {
        cout << "############### HASH ADT ###############\n" << endl;
        cout << "1.Insert \n2.Delete \n3.Search \n4.Display \n5.Exit \n" << endl;
        cout << "Enter your choice: ";
        cin  >> ch;

        switch (ch)
        {
        case 1:
            cout << "Key to insert: ";
            cin  >> key;
            ht.insert(key);
            cout << "\n";

            break;
        case 2:
            cout << "Key to delete: ";
            cin  >> key;
            ht.remove(key);
            cout << endl;

            break;
        case 3:
            cout << "Key to search: ";
            cin  >> key;
            ht.search(key);
            cout << endl;

            break;
        case 4:
            ht.display();
            cout << endl;

            break;
        case 5:
            loop = 0;

            break;
        default:
            cout << "Invalid Input!!!\n";

            break;
        }

        cout << "#######################################\n";
    }

    return 0;
}

void HashTable::insert(int key)
{
    int idx = hash(key);

    if (table[idx].front() != EMPTY) {
        for (int data : table[idx])
        {
            if (data == key) {
                cout << "Duplicate key at index [" << idx << "]\n";
                return;
            }
        }
    }
    table[idx].push_front(key);
}

void HashTable::remove(int key) 
{
    int idx = hash(key);

    if (table[idx].front() == EMPTY) {
        cout << "The key NOT IN table\n";
        return;
    }

    int size = table[idx].size();
    
    table[idx].remove(key);

    if (table[idx].size() < size) {
        cout << "The key deleted from index [" << idx << "]\n";
    } else {
        cout << "The key NOT IN table\n";
    }
}

int HashTable::search(int key)
{
    int idx = hash(key);

    if (table[idx].front() == EMPTY) {
        cout << "The key NOT IN table\n";
        return -1;
    }

    for (int data : table[idx])
    {
        if (data == key) {
            cout << "The key is at index [" << idx << "]\n";
            return -1;
        }
    }

    cout << "The key NOT IN table\n";
    return idx;
}

void HashTable::display()
{
    cout << "The hash table contents:\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << "[" << i << "] ";

        if (table[i].front() == EMPTY) {
            cout << "EMPTY\n";
        }
        else {
            for (int key : table[i])
            {
                if (key == EMPTY) { break; }

                cout << key << " ";
            }
            cout << endl;
        }
    }
}
