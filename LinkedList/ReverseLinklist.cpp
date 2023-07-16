#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void addAtTail(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        node *newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    else
    {

        node *newnode = new node(data);
        tail->next = newnode;
        tail = newnode;
    }
}

void Display(node *head)
{
    if (head == NULL)
        return;

    while (head != NULL)
    {

        cout << head->data << " ";
        head = head->next;
    }
    cout << " NULL";
}

int main()
{
    node *head = NULL;
    node *tail = NULL;
    int n;
    cin >> n;

    for (int i = 0; i > n; i++)
    {
        int x;
        cin >> x;

        addAtTail(head, tail, x);
    }
    return 0;
}
