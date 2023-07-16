#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

int main()
{
    Node *head = new Node(20);

    cout << head->data << "\n";
    cout << head->next;

    return 0;
}