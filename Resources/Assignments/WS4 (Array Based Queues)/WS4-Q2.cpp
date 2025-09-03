#include <iostream>

using namespace std;

class Vehicle
{
public:
    int crossTime;
    int waitTime;

    Vehicle(int crossTime = 0) : crossTime(crossTime), waitTime(0) {}
};

class TrafficQueue
{
    Vehicle *array;
    int size;
    int front;
    int rear;
    int count;

public:
    TrafficQueue(int size = 10) : size(size), front(0), rear(-1), count(0)
    {
        array = new Vehicle[size];
    }

    ~TrafficQueue()
    {
        delete[] array;
    }

    void enqueue(Vehicle vehicle)
    {
        if (count == size)
        {
            cout << "Queue Full";
            return;
        }
        rear = (rear + 1) % size;
        array[rear] = vehicle;
        count++;
    }

    Vehicle dequeue()
    {
        Vehicle vehicle = array[front];
        front = (front + 1) % size;
        count--;
        return vehicle;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    void processTraffic(int greenLightDuration)
    {
        int cumulativeWait = 0;
        while (!isEmpty())
        {
            Vehicle vehicle = dequeue();
            vehicle.waitTime = cumulativeWait;
            cumulativeWait += vehicle.crossTime;
            if (cumulativeWait >= greenLightDuration)
            {
                cumulativeWait = greenLightDuration;
            }
            cout << "Vehicle wait time: " << vehicle.waitTime << endl;
        }
    }
};

int main()
{
    int n, greenLightDuration;
    cout << "Enter number of vehicles and green light duration: ";
    cin >> n >> greenLightDuration;

    TrafficQueue queue;
    for (int i = 0; i < n; i++)
    {
        int crossTime;
        cout << "Enter crossing time for vehicle " << i << ": ";
        cin >> crossTime;
        queue.enqueue(Vehicle(crossTime));
    }

    cout << "Vehicle wait time" << endl;
    queue.processTraffic(greenLightDuration);

    return 0;
}