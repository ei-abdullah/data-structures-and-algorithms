#include <iostream>

using namespace std;

class Queue
{
    int front;
    int rear;
    int size;
    int count;
    int *queue;

public:
    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        queue = new int[size];
    }

    ~Queue()
    {
        delete[] queue;
    }

    void enqueue(double value)
    {
        if (isFull())
        {
            cout << "Queue Full" << endl;
            return;
        }

        rear++;
        queue[rear] = value;
    }

    double dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Empty" << endl;
            return -1;
        }

        front++;
        return queue[front];
    }

    bool isFull()
    {
        return rear == size - 1;
    }

    bool isEmpty()
    {
        return front == rear;
    }

    double first()
    {
        return queue[front];
    }
};

int main()
{

    return 0;
}