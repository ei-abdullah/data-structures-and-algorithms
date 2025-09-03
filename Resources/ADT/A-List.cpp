#include <iostream>
using namespace std;

class ArrayList
{
private:
    int *array;   // Dynamic array to hold the elements
    int size;     // Current number of elements in the list
    int capacity; // Maximum capacity of the list

public:
    // Constructor to initialize the list
    ArrayList(int cap)
    {
        if (cap <= 0)
        {
            cout << "Invalid capacity. Setting to 10 by default." << endl;
            cap = 10;
        }
        capacity = cap;
        size = 0;
        array = new int[capacity];
    }

    // Destructor to free the allocated memory
    ~ArrayList()
    {
        delete[] array;
    }

    // Get the element at a specific index
    int Get(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Invalid index!" << endl;
            return -1; // Error code
        }
        return array[index];
    }

    // Insert an element at a specific index
    void Insert(int index, int element)
    {
        if (index < 0 || index > size)
        {
            cout << "Invalid index!" << endl;
            return;
        }

        if (size == capacity)
        {
            cout << "List is full. Cannot insert more elements." << endl;
            return;
        }

        // Shift elements to the right to make space
        for (int i = size; i > index; i--)
        {
            array[i] = array[i - 1];
        }

        array[index] = element;
        size++;
    }

    // Append an element at the end of the list
    void Append(int element)
    {
        if (size == capacity)
        {
            cout << "List is full. Cannot append more elements." << endl;
            return;
        }

        array[size++] = element;
    }

    // Delete an element at a specific index
    void Delete(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Invalid index!" << endl;
            return;
        }

        // Shift elements to the left to fill the gap
        for (int i = index; i < size - 1; i++)
        {
            array[i] = array[i + 1];
        }

        size--;
    }

    // Display the elements of the list
    void Display()
    {
        if (size == 0)
        {
            cout << "List is empty!" << endl;
            return;
        }

        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    // Get the current size of the list
    int ListSize()
    {
        return size;
    }

    // Check if the list is empty
    bool isEmpty()
    {
        return size == 0;
    }
};

int main()
{
    ArrayList list(5); // Create a list with a capacity of 5

    // Append elements
    list.Append(10);
    list.Append(20);
    list.Append(30);

    cout << "List after appending elements: ";
    list.Display();

    // Insert elements
    list.Insert(1, 15);
    cout << "List after inserting 15 at index 1: ";
    list.Display();

    // Get element at index 2
    cout << "Element at index 2: " << list.Get(2) << endl;

    // Delete element at index 1
    list.Delete(1);
    cout << "List after deleting element at index 1: ";
    list.Display();

    // Check if the list is empty
    cout << "Is the list empty? " << (list.isEmpty() ? "Yes" : "No") << endl;

    // Try appending beyond capacity
    list.Append(40);
    list.Append(50);
    list.Append(60); // This should fail since capacity is 5
    cout << "List after appending beyond capacity: ";
    list.Display();

    return 0;
}
