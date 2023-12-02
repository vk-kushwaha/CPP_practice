#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* modifyList(Node* head) {
    if (!head || !head->next) {
        return head;
    }

    Node* oddHead = nullptr;
    Node* evenHead = nullptr;
    Node* oddTail = nullptr;
    Node* evenTail = nullptr;

    Node* current = head;

    while (current) {
        Node* nextNode = current->next;
        current->next = nullptr;  // Disconnect the current node from the list

        if (current->data % 2 == 1) {
            // Odd element
            if (!oddHead) {
                oddHead = current;
                oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = oddTail->next;
            }
        } else {
            // Even element
            if (!evenHead) {
                evenHead = current;
                evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = evenTail->next;
            }
        }

        current = nextNode;
    }

    if (oddHead) {
        oddTail->next = evenHead;
        return oddHead;
    } else {
        return evenHead;
    }
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = modifyList(head);
    printList(head);

    return 0;
}
