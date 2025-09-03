#include <iostream>
using namespace std;

class DoubleLinkedList
{
    struct Node
    {
        int data;
        Node *next;
        Node *prev;
    };

    Node *Head;
    Node *Tail;

public:
    DoubleLinkedList()
    {
        Head = Tail = NULL;
    }

    ~DoubleLinkedList()
    {
        if (!Head) // Empty list
            return;

        Node *current = Head;
        do
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != Head); // Stop when we loop back to Head
    }

    void Insert(int value, int position = 0)
    {
        Node *newNode = new Node{value, NULL, NULL};

        if (!Head) // Empty list
        {
            newNode->next = newNode;
            newNode->prev = newNode;
            Head = Tail = newNode;
            return;
        }

        if (position == 0) // Insert at the beginning
        {
            newNode->next = Head;
            newNode->prev = Tail;
            Head->prev = newNode;
            Tail->next = newNode;
            Head = newNode;
            return;
        }

        Node *current = Head;
        int currentIdx = 0;

        while (currentIdx < position - 1 && current->next != Head)
        {
            current = current->next;
            currentIdx++;
        }

        if (current == Tail) // Insert at the end
        {
            newNode->next = Head;
            newNode->prev = Tail;
            Tail->next = newNode;
            Head->prev = newNode;
            Tail = newNode;
        }
        else // Insert in the middle
        {
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }
    }

    void Delete(int value)
    {
        if (!Head) // Empty list
            return;

        Node *temp = Head;

        do
        {
            if (temp->data == value)
                break;
            temp = temp->next;
        } while (temp != Head);

        if (temp->data != value) // Value not found
            return;

        if (temp == Head && temp == Tail) // Single node case
        {
            delete temp;
            Head = Tail = NULL;
        }
        else if (temp == Head) // Delete the Head
        {
            Head = Head->next;
            Tail->next = Head;
            Head->prev = Tail;
            delete temp;
        }
        else if (temp == Tail) // Delete the Tail
        {
            Tail = Tail->prev;
            Tail->next = Head;
            Head->prev = Tail;
            delete temp;
        }
        else // Delete a middle node
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }

    void Display()
    {
        if (!Head)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *current = Head;
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != Head);
        cout << endl;
    }
};

int main()
{
    DoubleLinkedList dll;

    dll.Insert(10);
    dll.Insert(20);
    dll.Insert(30);

    cout << "List after insertion: ";
    dll.Display();

    dll.Delete(20);
    cout << "List after deleting 20: ";
    dll.Display();

    dll.Delete(10);
    cout << "List after deleting 10: ";
    dll.Display();

    dll.Delete(30);
    cout << "List after deleting 30: ";
    dll.Display();

    return 0;
}
