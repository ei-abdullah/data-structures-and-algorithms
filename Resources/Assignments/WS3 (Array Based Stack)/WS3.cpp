#include <iostream>
#include <string>

using namespace std;

class Stack
{
    string *elements;
    int size;
    int top;

public:
    Stack(int size = 10)
    {
        this->size = size;
        top = -1;
        elements = new string[size];
    }

    ~Stack()
    {
        delete[] elements;
    }

    void push(string element)
    {
        if (top + 1 == size)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        elements[++top] = element;
    }

    string pop()
    {
        return isEmpty() ? "" : elements[top--];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

class TextEditor
{
    Stack undoStack;
    Stack redoStack;
    string text;

public:
    void performAction(string action)
    {
        undoStack.push(action);
        text += action;
        while (!redoStack.isEmpty())
            redoStack.pop();
    }

    void undo()
    {
        if (!undoStack.isEmpty())
        {
            string lastAction = undoStack.pop();
            redoStack.push(lastAction);
            text.resize(text.size() - lastAction.size());
            cout << "Undo: " << lastAction << endl;
        }
        else
        {
            cout << "Nothing to undo." << endl;
        }
    }

    void redo()
    {
        if (!redoStack.isEmpty())
        {
            string lastUndone = redoStack.pop();
            undoStack.push(lastUndone);
            text += lastUndone;
            cout << "Redo: " << lastUndone << endl;
        }
        else
        {
            cout << "Nothing to redo." << endl;
        }
    }

    void displayText()
    {
        cout << "Current Text: " << text << endl;
    }
};

int main()
{
    TextEditor editor;

    editor.performAction("Hello");
    editor.displayText();

    editor.performAction(" World");
    editor.displayText();

    editor.undo();
    editor.displayText();

    editor.redo();
    editor.displayText();

    editor.performAction("!");
    editor.displayText();

    editor.undo();
    editor.displayText();

    return 0;
}