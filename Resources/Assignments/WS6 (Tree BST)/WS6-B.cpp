#include <iostream>
#include <string>
using namespace std;

class Record
{
public:
    int record_id;
    string name;
    int age;
    string address;

    Record(int record_id, string name, int age, string address)
        : record_id(record_id), name(name), age(age), address(address) {}

    void print()
    {
        cout << "Record ID: " << record_id
             << "\nName: " << name
             << "\nAge: " << age
             << "\nAddress: " << address
             << endl;
    }
};

class Node
{
public:
    Record data;
    Node *left;
    Node *right;

    Node(Record record) : data(record), left(NULL), right(NULL) {}
};

class BST
{
private:
    Node *root;

public:
    BST() : root(NULL) {}

    void Insert(Record record)
    {
        root = Insert(root, record);
    }

    Node *Insert(Node *p, Record record)
    {
        if (p == NULL)
            return new Node(record);

        if (record.record_id < p->data.record_id)
            p->left = Insert(p->left, record);
        else if (record.record_id > p->data.record_id)
            p->right = Insert(p->right, record);

        return p;
    }

    Node *Find(int id)
    {
        return Find(root, id);
    }

    Node *Find(Node *p, int id)
    {
        if (p == NULL || p->data.record_id == id)
            return p;

        if (id < p->data.record_id)
            return Find(p->left, id);
        else
            return Find(p->right, id);
    }

    void Delete(int id)
    {
        root = Delete(root, id);
    }

    Node *Delete(Node *p, int id)
    {
        if (p == NULL)
            return NULL;

        if (id < p->data.record_id)
            p->left = Delete(p->left, id);
        else if (id > p->data.record_id)
            p->right = Delete(p->right, id);
        else
        {
            if (p->left == NULL)
            {
                Node *temp = p->right;
                delete p;
                return temp;
            }
            else if (p->right == NULL)
            {
                Node *temp = p->left;
                delete p;
                return temp;
            }

            Node *q = InSucc(p->right);
            p->data = q->data;
            p->right = Delete(p->right, q->data.record_id);
        }
        return p;
    }

    int Height(Node *p)
    {
        if (p == NULL)
            return 0;
        return max(Height(p->left), Height(p->right)) + 1;
    }

    Node *InPre(Node *p)
    {
        while (p && p->right != NULL)
            p = p->right;
        return p;
    }

    Node *InSucc(Node *p)
    {
        while (p && p->left != NULL)
            p = p->left;
        return p;
    }

    void PrintInOrder(Node *p)
    {
        if (p == NULL)
            return;
        PrintInOrder(p->left);
        p->data.print();
        PrintInOrder(p->right);
    }

    void PrintTree()
    {
        PrintInOrder(root);
    }
};

int main()
{
    BST tree;
    tree.Insert(Record(1, "John Doe", 25, "123 Street"));
    tree.Insert(Record(2, "Jane Smith", 30, "456 Avenue"));
    tree.Insert(Record(3, "Alice Brown", 22, "789 Boulevard"));

    cout << "Tree before deletion:\n";
    tree.PrintTree();

    tree.Delete(2);

    cout << "\nTree after deleting record ID 2:\n";
    tree.PrintTree();

    return 0;
}
