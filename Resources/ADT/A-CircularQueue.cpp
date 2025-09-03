#include <iostream>
using namespace std;

class CircularQueue
{
    int size;
    int front;
    int rear;
    int *queue;

public:
    CircularQueue(int size)
    {
        this->size = size;
        front = 0;
        rear = -1;
        queue = new int[size];
    }

    void enqueue(int value)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Queue Full" << endl;
            return;
        }

        rear = (rear + 1) % size;
        queue[rear] = value;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Empty" << endl;
            return -1;
        }

        front = (front + 1) % size;
        return queue[front];
    }

    bool isFull()
    {
        return rear + 1 % size == front;
    }

    bool isEmpty()
    {
        return front == rear;
    }

    void display()
    {
        int i = front + 1;

        do
        {
            cout << queue[i] << " ";
            i = (i + 1) % size;
        } while (i != rear + 1);

        cout << endl;
    }
};

int main()
{

    return 0;
}