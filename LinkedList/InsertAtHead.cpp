#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {

        data = val;
        next = NULL;
    }
};

void InsertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {

        head = new Node(data);
        tail = head;
    }
    else
    {

        Node *newnode = new Node(data);
        newnode->next = head;
        head = newnode;
    }
}

void InsertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {

        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }
    else
    {

        Node *newnode = new Node(data);
        tail->next = newnode;
        tail = newnode;
    }
}

int LengthOfLL(Node *head, Node *tail)
{
    int count = 0;
    if (head == NULL)
    {
        return count;
    }
    else{
        while (head != NULL)
        {
            count++;
            head = head->next;
        }
    }
    return count;
}

void Display(Node *head)
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
    cout << "NULL\n";
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    InsertAtHead(head, tail, 30);
    InsertAtHead(head, tail, 20);
    InsertAtHead(head, tail, 10);

    Display(head);

    InsertAtTail(head, tail, 40);
    InsertAtTail(head, tail, 50);

    Display(head);

    cout << "Length of Linked List is = " << LengthOfLL(head,tail);
    return 0;
}