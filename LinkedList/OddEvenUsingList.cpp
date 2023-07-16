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

void Display(node *&head)
{

    if (head == NULL)
    {
        return;
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void ArrangeLinklist(node *head)
{

    node *oddhead = NULL;
    node *oddtail = NULL;
    node *evenhead = NULL;
    node *eventail = NULL;

    if (head == NULL || head->next == NULL)
        return;

    node *curr = head;
    while (curr != NULL)
    {

        if (curr->data % 2 != 0)
        {
            if (oddhead == NULL)
            {
                oddhead = curr;
                oddtail = curr;
            }
            else
            {
                oddtail->next = curr;
                oddtail = curr;
            }
        }
        else
        {

            if (evenhead == NULL)
            {
                evenhead = curr;
                eventail = curr;
            }
            else
            {

                eventail->next = curr;
                eventail = curr;
            }
        }

        curr = curr->next;
    }

    if (oddhead == NULL || evenhead == NULL)
        return;

    oddtail->next = evenhead;
    eventail->next = NULL;
    head = oddhead;
}
int main()
{

    node *head = NULL;
    node *tail = NULL;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        InsertAtTail(head, tail, x);
    }
    Display(head);
    ArrangeLinklist(head);

    Display(head);
    cout << endl;

    return 0;
}