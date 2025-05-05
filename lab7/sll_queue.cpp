#include <iostream>

class Queue {
    private:
        struct node {
            int data;
            struct node* next;
        };
            struct node* front;
            struct node* rear;

    public:
        Queue() {
            front = rear = NULL;
        }

        void enqueue(int val);
        int dequeue();
        int peek();
        bool isempty();
};

int main() {
    Queue queue;
    int loop = 1, ch = 0;

    while (loop) {
        int val;

        std::cout << "\n######## Queue ########\n";
        std::cout << "1.Enqueue\n"
                  << "2.Dequeue\n"
                  << "3.Peek\n"
                  << "4.Exit\n"
                  << "Enter your choice: ";
        std::cin >> ch;

        switch (ch) {
        case 1:
            std::cout << "Enter the value: ";
            std::cin >> val;
            queue.enqueue(val);
            break;
        case 2:
            val = queue.dequeue();
            if (val != -1) {
                std::cout << "The dequeued value is: " << val << std::endl;
            }
            break;
        case 3:
            val = queue.peek();
            if (val != -1) {
                std::cout << "The front is '" << val << "'\n";
            }
            break;
        case 4:
            loop = 0;
            break;
        default:
            std::cout << "Invalid input!!!\n";
            break;
        }

        std::cout << "#######################\n";
    }

    return 0;
}


bool Queue::isempty() {
    return front == NULL;
}

void Queue::enqueue(int val) {
    struct node* newNode = new struct node;
    newNode->data = val;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int Queue::dequeue() {
    if (isempty()) {
        std::cout << "The queue is empty!!\n";
        return -1;
    }

    int pop = front->data;
    struct node* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    delete temp;
    return pop;
}

int Queue::peek() {
    if (isempty()) {
        std::cout << "The queue is empty!!\n";
        return -1;
    }
    return front->data;
}
