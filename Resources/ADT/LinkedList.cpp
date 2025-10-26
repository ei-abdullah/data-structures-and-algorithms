#include <iostream>
using namespace std;

class LinkedList
{
    struct Node
    {
        int data;
        Node *next;
    };

    Node *head;

public:
    LinkedList() : head(NULL) {}

    ~LinkedList()
    {
        Node *p = head;
        while (p)
        {
            Node *temp = p;
            p = p->next;
            delete temp;
        }
    }
};

void LinkedList::Insert(int index, int value)
{
    if (index < 0 || index > ListCount())
    {
        cout << "Invalid Index" << endl;
        return;
    }

    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;

    if (index == 0)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        Node *p = head;
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        temp->next = p->next;
        p->next = temp;
    }
}

int LinkedList::FindNode(int value) const
{
    Node *p = head;
    int index = 0;

    while (p)
    {
        if (p->data == value)
            return index; // Return the index without printing
        p = p->next;
        index++;
    }

    return -1; // Value not found
}

int LinkedList::DeleteNode(int index)
{
    if (index < 0 || index >= ListCount())
    {
        cout << "Invalid Index" << endl;
        return 0;
    }

    Node *p = head, *q = NULL;
    int value = 0;

    if (index == 0)
    {
        q = head;
        value = head->data;
        head = head->next;
        delete q;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        value = p->data;
        delete p;
    }

    return value;
}

void LinkedList::DisplayList() const
{
    Node *p = head;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int LinkedList::ListCount() const
{
    int count = 0;
    Node *p = head;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

bool LinkedList::isEmpty() const
{
    return !head;
}

void LinkedList::InsertLast(int value)
{
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;

    if (!head)
        head = temp;
    else
    {
        Node *last = head;
        while (last->next)
            last = last->next;
        last->next = temp;
    }
}

void LinkedList::RemoveDuplicate()
{
    Node *p = head;
    Node *q = head->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

void LinkedList::ConcatList(LinkedList &list)
{
    if (!head)
    {
        head = list.head;
        return;
    }

    Node *p = head;
    while (p->next)
        p = p->next;

    p->next = list.head;
}

void LinkedList::insertLast(int value)
{
    Node *temp = new Node{value, NULL};

    Node *p = head;

    while (p)
    {
        p = p->next;
    }

    p->next = temp;
}

int main()
{
    LinkedList list1;
    LinkedList list2;

    list1.InsertLast(4);
    list1.InsertLast(4);
    list1.InsertLast(8);
    list1.InsertLast(8);
    list1.InsertLast(3);
    list1.InsertLast(3);
    list1.InsertLast(3);

    list2.InsertLast(5);
    list2.InsertLast(5);
    list2.InsertLast(4);
    list2.InsertLast(3);

    list1.DisplayList();

    list1.RemoveDuplicate();

    list1.DisplayList();

    list1.ConcatList(list2);

    list1.DisplayList();

    return 0;
}
