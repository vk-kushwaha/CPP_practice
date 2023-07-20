#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

Node *head = new Node(0);
int getSize()
{
    int size = 0;
    Node *curr = head->next;
    while (curr != NULL)
    {
        size++;
        curr = curr->next;
    }
    return size;
}
int get(int index)
{
    if (index < 0 || index > getSize())
    {
        return -1;
    }
    Node *curr = head;
    for (int i = 0; i <= index; i++)
    {
        curr = curr->next;
    }
    return curr->val;
}
void addAtHead(int val)
{
    if (head == NULL)
    {
        head = new Node(val);
    }
    else
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
}
void addAtTail(int val)
{
    Node *newnode = new Node(val);
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newnode;
}
void addAtIndex(int index, int val)
{
    if (index < 0)
        addAtHead(val);

    if (index >= getSize())
        addAtTail(val);

    Node *curr = head;
    for (int i = 0; i < index; i++)
    {
        curr = curr->next;
    }
    Node *tmp = curr->next;
    Node *newnode = new Node(val);
    curr->next = newnode;
    newnode->next = tmp;
}
void deleteAtIndex(int index)
{
    if (index < 0 || index >= getSize())
        return;

    Node *curr = head;

    for (int i = 0; i < index; i++)
    {
        curr = curr->next;
    }
    Node *nodetobedelet = curr->next;
    curr->next = nodetobedelet->next;
    delete nodetobedelet;
}

void deleteLinkedList()
{
    Node *curr = head->next;
    while (curr != NULL)
    {
        Node *nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    head->next = NULL;
}

int main()
{

    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "addAtHead")
        {
            int data;
            cin >> data;
            addAtHead(data);
        }
        else if (s == "addAtTail")
        {
            int data;
            cin >> data;
            addAtTail(data);
        }
        else if (s == "addAtIndex")
        {
            int index, data;
            cin >> index;
            cin >> data;
            addAtIndex(index, data);
        }
        else if (s == "get")
        {
            int index;
            cin >> index;
            cout << get(index) << " ";
        }
        else
        {
            int index;
            cin >> index;
            deleteAtIndex(index);
        }
    }

    deleteLinkedList();
    return 0;
}
