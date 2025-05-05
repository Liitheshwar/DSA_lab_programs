#include <iostream>

#define LEN 5

class Queue
{
    private:
        int arr[LEN];
        int front, rear;

    public:
        Queue()
        {
            front = rear = -1;
        }

        void enqueue(int val);
        int dequeue();
        int peek();

        bool isempty();
};

int main() {
    Queue queue;
    int loop = 1, ch = 0;

    while(loop)                             
    {
        int val;

        std::cout << "\n######## Queue ########\n";
        std::cout << "1.Enqueue\n"
             << "2.Dequeue\n"
             << "3.Peek\n"
             << "4.Exit\n" << std::endl
             << "Enter your choice: ";
        std::cin  >> ch;

        switch (ch)
        {
        case 1:
            std::cout << "Enter the value: ";
            std::cin  >> val;
            queue.enqueue(val);

            break;
        case 2:
            val = queue.dequeue();
            if(val != -1) {
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

void Queue::enqueue(int val)
{
    if (front == -1) {
        front = rear = 0;
        arr[rear] = val;
        rear++;
        return;
    }

    if (rear == LEN) {
        std::cout << "The end of queue reached!!\n";
        return;
    }

    arr[rear] = val;
    rear++;
}

int Queue::dequeue()
{
    if (isempty()) {
        std::cout << "The queue is empty!!\n";
        return -1;
    }

    int pop = arr[front];
    front++;
    return pop;
}

int Queue::peek()
{
    if (isempty()) {
        std::cout << "The queue is empty!!\n";
        return -1;
    }

    return arr[front];
}

bool Queue::isempty()
{
    if(front == rear) {
        return true;
    }

    return false;
}

