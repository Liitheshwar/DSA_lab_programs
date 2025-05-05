#include <iostream>
#include <vector>
#include <algorithm>

class PriorityQueue
{
    private:
        std::vector<int> heap;
        int current;

        void heapify_up(int idx);
        void heapify_down(int idx);

    public:
        PriorityQueue()
        {
            current = -1;
        }

        void insert(int val);
        int remove();
        void display();
        bool search(int val);
        void heapsort();
};

int main() {
    PriorityQueue maxheap;

    maxheap.insert(20);
    maxheap.insert(10);
    maxheap.insert(25);
    maxheap.insert(40);
    maxheap.display();
    std::cout << maxheap.remove();
    
    maxheap.display();
    return 0;
}

void PriorityQueue::heapify_up(int idx)
{
    while(idx > 0 && heap[(idx-1)/2] < heap[idx])
    {
        std::swap(heap[(idx - 1) / 2], heap[idx]);
        idx = (idx-1)/2;
    }
}

void PriorityQueue::heapify_down(int idx)
{
    while(true) 
    {
        int left = 2 * idx +1;
        int right = 2 * idx +2;
        int largest = idx;

        if (left <= current && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right <= current && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != idx) {
            std::swap(heap[largest], heap[idx]);
            idx = largest;
        }
        else {
            break;
        }
    }
    
}


void PriorityQueue::insert(int val)
{
    current++;
    heap[current] = val;
    heapify_up(current);
}

int PriorityQueue::remove()
{
    if (current == -1) {
        std::cout << "Heap is empty.\n";
        return -1;
    }

    int val = heap[0];
    heap[0] = heap[current];
    current--;
    heapify_down(0);
    return val;
}

void PriorityQueue::display()
{
    if (current == -1) {
        std::cout << "Heap is empty.\n";
        return;
    }
    
    std::cout << "Heap elements: ";
    for (int i = 0; i < current+1; i++) {
        std::cout << heap[i] << " ";
    }
    std::cout << "\n";
}
