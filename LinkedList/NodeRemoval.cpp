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

int lengthOfLL(node *head)
{
    int cnt = 0;

    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }

    return cnt;
}

void DeleteFromEnd(node *&head, node *&tail, int del)
{

    if (del == 0)
    {
        head = head->next;
        return;
    }
    else if (del > lengthOfLL(head))
    {
        return;
    }

    else
    {

        node *curr = head;
        for (int i = 1; i < del; i++)
        {
            curr = curr->next;
        }

        node *deletenode = curr->next;
        curr->next = deletenode->next;
        delete deletenode;
    }
}

void display(node *head)
{
    if (head == NULL)
        return;

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    int n, pos;
    cin >> n >> pos;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        addAtTail(head, tail, x);
    }
    int del = lengthOfLL(head) - pos;

    DeleteFromEnd(head, tail, del);

    display(head);

    return 0;
}