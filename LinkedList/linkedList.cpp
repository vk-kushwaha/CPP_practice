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
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

void InsertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        InsertAtHead(head, tail, data);
    }
    else
    {
        Node *newnode = new Node(data);
        tail->next = newnode;
        tail = newnode;
    }
}

void deleteAtHead(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << " LL is empty cant delete";
    }

    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }

    else
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteAtTail(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "LL is emply";
        return;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        Node *current = head;
        while (current->next != tail)
        {
            current = current->next;
        }
        current->next = NULL;
        delete tail;
        tail = current;
    }
}



void Display(Node *head)
{
    if (head == NULL)
        return;

    while (head != NULL)
    {

        cout << head->data << "->";
        head = head->next;
    }
    cout << " NULL";
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    InsertAtHead(head, tail, 10);
    InsertAtHead(head, tail, 20);
    InsertAtHead(head, tail, 30);
    InsertAtHead(head, tail, 40);
    Display(head);
    cout << endl;
    InsertAtTail(head, tail, 50);
    InsertAtTail(head, tail, 60);

    Display(head);
    cout << endl;

    deleteAtHead(head, tail);
    Display(head);
    cout << endl;

    deleteAtTail(head, tail);
    Display(head);
    cout << endl;

    return 0;
}