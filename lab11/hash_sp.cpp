#include <iostream>

#define SIZE 10
#define EMPTY -1

using namespace std;

class HashTable
{
    private:
        int table[SIZE];

        int hash(int key);

    public:
        HashTable()
        {
            for (int i = 0; i < SIZE; i++)
            {
                table[i] = EMPTY;
            }
        }

        void insert(int key);
        void remove(int key);
        int  search (int key);
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

int HashTable::hash(int key)
{
    return key % SIZE;
}

void HashTable::insert(int key)
{
    int idx = hash(key);
    int start_idx = idx;

    while (table[idx] != EMPTY)
    {
        if (table[idx] == key) {
            cout << "Duplicate key " << key << " at index " << idx << endl;
            return;
        }

        idx = hash(idx+1);
        if (idx == start_idx) {
            cout << "The hash table is FULL!!\n";
            return;
        }
    }

    table[idx] = key;
}

void HashTable::remove(int key)
{
    int idx = hash(key);
    int start_idx = idx;

    while(table[idx] != key)
    {
        idx = hash(idx+1);
        if (idx == start_idx) {
            cout << "The key NOT IN hash table\n";
            return;
        }
    }

    table[idx] = EMPTY;
    cout << "Deleted key " << key << " from hash table\n";
}

int HashTable::search(int key)
{
    int idx = hash(key);
    int start_idx = idx;

    while(table[idx] != key)
    {
        idx = hash(idx+1);
        if (idx == start_idx) {
            cout << "The key NOT IN hash table\n";
            return -1;
        }
    }

    cout << "The key is present at index " << idx << endl;
    return idx;
}

void HashTable::display()
{
    cout << "The table contents:\n";
    for(int i = 0; i < SIZE; i++) 
    {
        cout << "[" << i << "]: ";
        if (table[i] != EMPTY) {
            cout << table[i] << endl;
        }
        else {
            cout << "EMPTY\n";
        }  
    }
}