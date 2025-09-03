#include <iostream>

using namespace std;

class Document
{
public:
    int priority;
    int position;

    Document(int priority = 0, int position = 0)
    {
        this->priority = priority;
        this->position = position;
    }
};

class Queue
{
    Document *array;
    int size;
    int front;
    int rear;
    int count;

public:
    Queue(int size = 10) : size(size), front(0), rear(-1), count(0)
    {
        array = new Document[size];
    }

    ~Queue()
    {
        delete[] array;
    }

    void enqueue(Document doc)
    {
        if (count == size)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        rear = (rear + 1) % size;
        array[rear] = doc;
        count++;
    }

    Document dequeue()
    {
        Document doc = array[front];
        front = (front + 1) % size;
        count--;
        return doc;
    }

    Document peek()
    {
        return array[front];
    }

    bool isEmpty()
    {
        return count == 0;
    }

    int size()
    {
        return count;
    }

    int maxPriority()
    {
        int maxPri = array[front].priority;
        for (int i = 0; i < count; i++)
        {
            int idx = (front + 1) % size;
            maxPri = max(maxPri, array[idx].priority);
        }

        return maxPri;
    }
};

int main()
{
    int n, m;
    cout << "Enter number of documents and position of target document: ";
    cin >> n >> m;

    Queue queue;
    for (int i = 0; i < n; i++)
    {
        int pri;
        cout << "Enter priority for document " << i << ": ";
        cin >> pri;
        queue.enqueue(Document(pri, i));
    }

    int steps = 0;
    while (!queue.isEmpty())
    {
        Document currentDoc = queue.peek();
        if (currentDoc.priority == queue.maxPriority())
        {
            queue.dequeue();
            steps++;
            if (currentDoc.position == 0)
            {
                cout << "Step required to print target document: " << steps << endl;
                break;
            }
        }
        else
        {
            queue.enqueue(queue.dequeue());
        }
    }

    return 0;
}