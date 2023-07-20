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

class Solution
{

public:
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

    node *Sortlist(node *&head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        node *middle = findmiddle(head);
        node *nexttomiddle = middle->next;
        middle->next = NULL;

        node *left = Sortlist(head);
        node *right = Sortlist(nexttomiddle);

        node *sortedlist = merge(left, right);

        return sortedlist;
    }

    node *findmiddle(node *head)
    {
        node *slow = head;
        node *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    node *merge(node *left, node *right)
    {
        node *dummy = new node(0);
        node *curr = dummy;

        while (left != NULL && right != NULL)
        {
            if (left->data < right->data)
            {
                curr->next = left;
                left = left->next;
            }
            else
            {

                curr->next = right;
                right = right->next;
            }

            curr = curr->next;
        }

        if (left != NULL)
            curr->next = left;
        if (right != NULL)
            curr->next = right;

        return dummy->next;
    }
};
int main()
{

    node *head = NULL;
    node *tail = NULL;

    int n;
    cin >> n;

    Solution solution;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        solution.addAtTail(head, tail, x);
    }

    head = solution.Sortlist(head);

    node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}