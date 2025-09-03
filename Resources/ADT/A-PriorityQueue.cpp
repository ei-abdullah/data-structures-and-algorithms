#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the priority queue

class PriorityQueue
{
private:
    int arr[MAX_SIZE]; // Array to hold the elements
    int size;          // Number of elements in the priority queue

public:
    // Constructor to initialize the priority queue
    PriorityQueue() : size(0) {}

    // Function to insert an element (enqueue) into the queue
    void enqueue(int value)
    {
        if (size == MAX_SIZE)
        {
            cout << "Queue is full! Cannot enqueue." << endl;
            return;
        }

        // Insert the element at the end
        arr[size++] = value;

        // Sort the array in ascending order to maintain priority (smallest value has highest priority)
        sort(arr, arr + size);
    }

    // Function to remove and return the highest priority element (dequeue)
    int dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return -1;
        }

        // The element at the front (arr[0]) has the highest priority (smallest value)
        int highestPriorityElement = arr[0];

        // Shift all elements to the left by one position
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        // Decrease the size of the queue
        size--;

        return highestPriorityElement;
    }

    // Function to display the elements in the priority queue
    void display()
    {
        if (size == 0)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Priority Queue: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Function to return the element with the highest priority without removing it
    int peek()
    {
        if (size == 0)
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[0]; // The smallest value has the highest priority
    }
};

int main()
{
    PriorityQueue pq;

    pq.enqueue(30);
    pq.enqueue(20);
    pq.enqueue(50);
    pq.enqueue(10);

    pq.display(); // Output: 10 20 30 50 (10 has the highest priority)

    cout << "Dequeued element: " << pq.dequeue() << endl; // Output: 10
    pq.display();                                         // Output: 20 30 50

    cout << "Element with highest priority: " << pq.peek() << endl; // Output: 20

    return 0;
}
