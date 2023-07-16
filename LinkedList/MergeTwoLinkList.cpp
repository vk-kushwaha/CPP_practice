#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void InsertAtTail(Node*& head, Node*& tail, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void Display(Node* head) {
    if (head == NULL) {
        return;
    }
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* MergeTwoLists(Node* head1, Node* head2) {
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    Node* mergedLink = NULL;
    Node* tail = NULL;

    if (head1->data <= head2->data) {
        mergedLink = head1;
        tail = head1;
        head1 = head1->next;
    }
    else {
        mergedLink = head2;
        tail = head2;
        head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        }
        else {
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
    }

    if (head1 != NULL)
        tail->next = head1;
    else
        tail->next = head2;

    return mergedLink;
}

int main() {
    int Test;
    cin >> Test;

    while (Test--) {
        int link1, link2;
        cin >> link1;
        Node* head1 = NULL;
        Node* tail1 = NULL;

        for (int i = 0; i < link1; i++) {
            int x;
            cin >> x;
            InsertAtTail(head1, tail1, x);
        }

        cin >> link2;
        Node* head2 = NULL;
        Node* tail2 = NULL;

        for (int i = 0; i < link2; i++) {
            int x;
            cin >> x;
            InsertAtTail(head2, tail2, x);
        }

        Node* mergedList = MergeTwoLists(head1, head2);
        Display(mergedList);
        cout << endl;
    }

    return 0;
}