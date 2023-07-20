#include <iostream>
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

void addAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    else
    {

        Node *newnode = new Node(data);
        tail->next = newnode;
        tail = newnode;
    }
}
int Middle(Node *head)
{
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    if (fast == NULL)
        return prev->val;
    else
        return slow->val;
}
int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {

        int x;
        cin >> x;

        addAtTail(head, tail, x);
    }
    int ans = Middle(head);

    cout << ans << endl;

    return 0;
}