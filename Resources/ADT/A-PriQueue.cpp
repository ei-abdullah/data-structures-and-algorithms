#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 5;

class PriQueue
{
public:
    struct data
    {
        char job[MAX];
        int prNo;
        int ordNo;
    };

    data array[MAX];
    int front;
    int rear;

    PriQueue()
    {
        front = rear = -1;
        for (int i = 0; i < MAX; i++)
        {
            strcpy(array[i].job, "");
            array[i].prNo = array[i].ordNo = 0;
        }
    }

    void Add(data value)
    {
        if (rear == MAX - 1)
        {
            cout << "Queue Full" << endl;
            return;
        }

        // Increment rear for the new element
        rear++;

        // Find the correct position for the new element
        int i;
        for (i = rear - 1; i >= front; i--)
        {
            if (array[i].prNo < value.prNo ||
                (array[i].prNo == value.prNo && array[i].ordNo < value.ordNo))
            {
                break;
            }
            array[i + 1] = array[i]; // Shift element forward
        }

        // Insert the new element at the correct position
        array[i + 1] = value;

        // Update front if it's the first element added
        if (front == -1)
            front = 0;
    }

    data Delete()
    {
        data temp = {"", 0, 0};

        if (front == -1)
        {
            cout << "Queue Empty" << endl;
            return temp;
        }

        temp = array[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;

        return temp;
    }
};

int main()
{
    PriQueue pq;

    PriQueue::data job1 = {"Job1", 2, 1};
    PriQueue::data job2 = {"Job2", 1, 2};
    PriQueue::data job3 = {"Job3", 2, 3};

    pq.Add(job1);
    pq.Add(job2);
    pq.Add(job3);

    cout << "Deleted job: " << pq.Delete().job << endl;
    cout << "Deleted job: " << pq.Delete().job << endl;
    cout << "Deleted job: " << pq.Delete().job << endl;

    return 0;
}
