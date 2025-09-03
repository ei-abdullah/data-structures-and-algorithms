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
    int pos;

public:
    DoubleLinkedList()
    {
        Head = Tail = NULL;
        pos = 0;
    }
    ~DoubleLinkedList()
    {
        Node *current = Head;
        while (current)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void Insert(int value, int position = 0)
    {
        Node *newNode = new Node{value, NULL, NULL};

        if (!Head)
        {
            newNode->next = Head;
            Head = Tail = newNode;
            return;
        }

        if (position == 0)
        {
            newNode->next = Head;
            Head->prev = newNode;
            Head = newNode;
            return;
        }

        Node *current = Head;
        int currentIdx = 0;

        while (current && currentIdx < position - 1)
        {
            current = current->next;
            currentIdx++;
        }

        if (!current || !current->next)
        {
            Tail->next = newNode;
            newNode->prev = Tail;
            Tail = newNode;
        }
        else
        {
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }
    }

    void Delete(int value)
    {

        if (!Head)
            return;

        Node *temp = Head;

        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp)
            return;

        if (temp == Head)
        {
            Head = Head->next;
            if (Head)
                Head->prev = NULL;
            else
                Tail = NULL;
        }
        else if (temp == Tail)
        {
            Tail = Tail->prev;
            Tail->next = NULL;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void Display()
    {
        Node *current = Head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
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

    dll.Delete(40); // Attempting to delete a non-existent value
    cout << "List after attempting to delete 40: ";
    dll.Display();

    return 0;
}
