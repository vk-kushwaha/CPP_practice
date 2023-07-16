// Program to creat, print and modify Linked List.

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
        head = new Node(data);
        tail = head;
    }
    else
    {
        Node *newnode = new Node(data);
        tail->next = newnode;
        tail = newnode;
    }
}

void PrintReverse(Node *&head, Node *&tail)
{

    if (head == NULL)
    {
        return;
    }

    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {

        Node *save = curr->next;
        curr->next = prev;
        prev = curr;
        curr = save;
    }

    tail = head;
    head = prev;
}

int NoOfNodes(Node *head, Node *tail)
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
    cout << "NULL\n\n";
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    InsertAtHead(head, tail, 30);
    InsertAtHead(head, tail, 20);
    InsertAtHead(head, tail, 10);

    cout << "By Insert at head method\n";
    Display(head);

    InsertAtTail(head, tail, 40);
    InsertAtTail(head, tail, 50);
    InsertAtTail(head, tail, 60);
    cout << "By Insert at Tail method\n";
    Display(head);

    PrintReverse(head, tail);
    cout << "\nReverse print of Linked List\n";
    Display(head);

    cout << "\nTotal Number of Nodes are = " << NoOfNodes(head, tail);
    return 0;
}