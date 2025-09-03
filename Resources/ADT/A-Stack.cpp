#include <iostream>
using namespace std;

class Stack
{
    int top;
    int *stack;
    int size;

public:
    Stack(int size = 10)
    {
        this->size = size;
        stack = new int[size];
        top = -1;
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        stack[top] = value;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        int value = stack[top];
        top--;
        return value;
    }

    int peek(int index)
    {
        if (top - index + 1 < 0)
            cout << "Invalid address" << endl;

        int value = stack[top - index + 1];
        return value;
    }

    bool isFull()
    {
        return top == size - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{

    return 0;
}