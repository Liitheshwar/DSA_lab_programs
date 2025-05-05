#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    void insert(int val);
    int deleteMax();
    void display();
    void search(int val);
    void heapSort();
};

// ------------ MAIN FUNCTION AT TOP ------------

int main() {
    PriorityQueue pq;
    int choice, value, pop;

    while(true) {
        cout << "\n--- Priority Queue Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Display\n4. Search\n5. Sort (Heap Sort)\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.insert(value);
                break;
            case 2:
                pop = pq.deleteMax();
                if (pop != -1) {
                    cout << "Deleted: " << pop << endl;
                }
                break;
            case 3:
                pq.display();
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                pq.search(value);
                break;
            case 5:
                pq.heapSort();
                break;
            case 6:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}



void PriorityQueue::heapifyUp(int index) {
    while(index > 0 && heap[(index - 1) / 2] < heap[index]) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void PriorityQueue::heapifyDown(int index) {
    int size = heap.size();
    while(index < size) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if(left < size && heap[left] > heap[largest])
            largest = left;
        if(right < size && heap[right] > heap[largest])
            largest = right;

        if(largest == index) break;

        swap(heap[index], heap[largest]);
        index = largest;
    }
}

void PriorityQueue::insert(int val) {
    heap.push_back(val);
    heapifyUp(heap.size() - 1);
    cout << "Inserted: " << val << endl;
}

int PriorityQueue::deleteMax() {
    if(heap.empty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    int pop =  heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return pop;
}

void PriorityQueue::display() {
    if(heap.empty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Priority Queue (Max Heap): ";
    for(int val : heap)
        cout << val << " ";
    cout << endl;
}

void PriorityQueue::search(int val) {
    for(int i = 0; i < heap.size(); i++) {
        if(heap[i] == val) {
            cout << val << " found at index " << i << endl;
            return;
        }
    }
    cout << val << " not found!" << endl;
}

void PriorityQueue::heapSort() {
    vector<int> temp = heap;
    vector<int> sorted;

    while(!heap.empty()) {
        sorted.push_back(heap[0]);
        deleteMax();
    }

    cout << "Heap Sorted (Descending): ";
    for(int val : sorted)
        cout << val << " ";
    cout << endl;

    heap = temp;
}
