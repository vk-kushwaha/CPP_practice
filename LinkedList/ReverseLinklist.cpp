

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
}

void ReverseLinkedlist(node *&head, int start, int end)
{
    if (head == NULL || head->next == NULL || start == end)
        return;

    node *dummy = new node(0);
    dummy->next = head;
    node *prev = dummy;

    for (int i = 1; i < start; i++)
    {
        if (prev->next == NULL)
            return; 
        prev = prev->next;
    }

    node *curr = prev->next;
    for (int i = 0; i < end - start; i++)
    {
        node *temp = prev->next;
        prev->next = curr->next;
        curr->next = curr->next->next;
        prev->next->next = temp;
    }

    head = dummy->next;
    delete dummy;
}

/*node *prev_tail = prev;
node *sublist_tail = curr;

while (curr && (curr->data != end || curr == NULL))
{
    node *next_node = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next_node;
}

if (prev_tail)
{
    prev_tail->next = prev;
}
else
{
    head = prev;
}

sublist_tail->next = curr;
curr = prev;*/

int main()
{
    node *head = NULL;
    node *tail = NULL;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        addAtTail(head, tail, x);
    }

    int start, end;
    cin >> start >> end;

    ReverseLinkedlist(head, start, end);
    Display(head);

    return 0;
}
