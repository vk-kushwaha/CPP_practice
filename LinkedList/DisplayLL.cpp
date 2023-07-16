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

void InsertAthead(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        tail = head;
    }
    else
    {
        node *newnode = new node(data);
        newnode->next = head;
        head = newnode;
    }
}

void InsertAtTail(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        tail = head;
    }
    else
    {

        node *newnode = new node(data);
        tail->next = newnode;
        tail = newnode;
    }
}

void ReversePrint(node *&head, node *&tail)
{
    node *curr = head;
    node *prev = NULL;

    if (head == NULL)
        return;

    while (curr != NULL)
    {
        node *save = curr->next;
        curr->next = prev;
        prev = curr;
        curr = save;
    }

    tail = head;
    head = prev;
}

int NumberOfNode(node *head)
{
    int count = 0;
    if (head == NULL)
    {
        return count;
    }
    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

void Display(node *head)
{

    if (head == NULL)
    {
        return;
    }
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL";
}

int main()
{
    node *head = NULL;
    node *tail = NULL;

    InsertAthead(head, tail, 1);
    InsertAthead(head, tail, 3);
    InsertAthead(head, tail, 5);
    InsertAthead(head, tail, 7);
    InsertAthead(head, tail, 9);
    InsertAthead(head, tail, 11);
    Display(head);
    cout << endl;

    InsertAtTail(head, tail, 0);
    InsertAtTail(head, tail, 10);

    Display(head);

    cout << "\nNumber of Nodes => " << NumberOfNode(head);
    // ReversePrint(head, tail);
    // Display(head);

    return 0;
}