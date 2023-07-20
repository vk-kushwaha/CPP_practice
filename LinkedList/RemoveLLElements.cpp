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

void RemoveLLElement(node *&head, int k)
{
    if (head == NULL || head->next == NULL)
        return;

    node *curr = head;
    node *prev = NULL;
    while (curr != NULL)
    {
        if (curr->data == k)
        {
            if (head == curr)
            {
                head = curr->next;
                delete curr;
                curr = head;
            }
            else
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
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
}

int main()
{
    node *head = NULL;
    node *tail = NULL;
    int N, k;
    cin >> N >> k;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        addAtTail(head, tail, x);
    }

    RemoveLLElement(head, k);

    Display(head);

    return 0;
}