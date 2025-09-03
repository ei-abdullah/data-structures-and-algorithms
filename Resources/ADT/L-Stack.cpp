#include <iostream>
using namespace std;

class Stack
{
    struct Node
    {
        int data;
        Node *next;
    };

    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    ~Stack()
    {
        Node *p = top;
        while (top)
        {
            top = top->next;
            delete p;
            p = top;
        }
    }

    void push(int value)
    {
        Node *temp = new Node;

        temp->data = value;
        temp->next = top;
        top = temp;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        Node *p = top;
        int value = p->data;
        top = top->next;
        delete p;

        return value;
    }

    int peek(int index)
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        Node *p = top;

        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }

        if (!p)
        {
            return -1;
        }

        return p->data;
    }

    bool isEmpty()
    {
        return !top;
    }
};

int main()
{

    return 0;
}