#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* mergeSortedLists(Node* head1, Node* head2) {
    if (head1 == nullptr) {
        return head2;
    }
    if (head2 == nullptr) {
        return head1;
    }

    Node* mergedHead = nullptr;
    Node* tail = nullptr;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data <= head2->data) {
            if (mergedHead == nullptr) {
                mergedHead = head1;
                tail = head1;
            } else {
                tail->next = head1;
                tail = head1;
            }
            head1 = head1->next;
        } else {
            if (mergedHead == nullptr) {
                mergedHead = head2;
                tail = head2;
            } else {
                tail->next = head2;
                tail = head2;
            }
            head2 = head2->next;
        }
    }

    if (head1 != nullptr) {
        tail->next = head1;
    }
    if (head2 != nullptr) {
        tail->next = head2;
    }

    return mergedHead;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N1, N2;
        cin >> N1;

        Node* head1 = nullptr;
        Node* tail1 = nullptr;

        for (int i = 0; i < N1; i++) {
            int val;
            cin >> val;
            Node* newNode = new Node(val);
            if (head1 == nullptr) {
                head1 = newNode;
                tail1 = newNode;
            } else {
                tail1->next = newNode;
                tail1 = newNode;
            }
        }

        cin >> N2;

        Node* head2 = nullptr;
        Node* tail2 = nullptr;

        for (int i = 0; i < N2; i++) {
            int val;
            cin >> val;
            Node* newNode = new Node(val);
            if (head2 == nullptr) {
                head2 = newNode;
                tail2 = newNode;
            } else {
                tail2->next = newNode;
                tail2 = newNode;
            }
        }

        Node* mergedHead = mergeSortedLists(head1, head2);

        printList(mergedHead);
    }

    return 0;
}
