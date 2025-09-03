#include <iostream>
using namespace std;

class Queue
{
    struct Node
    {
        int data;
        Node *next;
    };

    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    ~Queue()
    {
        // Free all allocated memory
        while (!isEmpty())
        {
            dequeue();
        }
    }

    void enqueue(int value)
    {
        Node *temp = new Node;
        temp->data = value;
        temp->next = NULL;

        if (front == NULL)
            front = rear = temp;
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Empty" << endl;
            return -1;
        }

        Node *p = front;
        front = front->next;
        int value = p->data;
        delete p;

        // If the queue is now empty, set rear to NULL
        if (front == NULL)
            rear = NULL;

        return value;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void display()
    {
        Node *p = front;

        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl; // Add newline for cleaner output
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: ";
    q.display();

    cout << "Dequeue: " << q.dequeue() << endl;

    cout << "Queue after dequeue: ";
    q.display();

    return 0;
}
