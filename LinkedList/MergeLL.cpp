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

void Display(node *head)
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

node *MergeTwoLink(node *&head1, node *&head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    node *mergedLink = NULL;
    node *tail = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data > head2->data)
        {
            if (mergedLink == NULL)
            {
                mergedLink = head2;
                tail = head2;
            }
            else
            {

                tail->next = head2;
                tail = head2;
            }
            head2 = head2->next;
        }

        else
        {
            if (mergedLink == NULL)
            {
                mergedLink = head1;
                tail = head1;
            }
            else
            {

                tail->next = head1;
                tail = head1;
            }
            head1 = head1->next;
        }

        if (head1 != NULL)
        {
            tail->next = head1;
        }
        else
            tail->next = head2;
    }
    return mergedLink;
}

int main()
{

    node *head1 = NULL;
    node *tail1 = NULL;

    node *head2 = NULL;
    node *tail2 = NULL;

    int test;
    cin >> test;

    while (test--)
    {
        int link1;
        cin >> link1;

        for (int i = 0; i < link1; i++)
        {
            int x;
            cin >> x;

            InsertAtTail(head1, tail1, x);
        }

        int list2;
        cin >> list2;

        for (int i = 0; i < list2; i++)
        {
            int y;
            cin >> y;

            InsertAtTail(head2, tail2, y);
        }
    }

    node *ans = MergeTwoLink(head1, head2);

    Display(ans);
    cout << endl;

    return 0;
}