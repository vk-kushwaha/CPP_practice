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

class MyLinkedList {
public:
    Node* head;
    
    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        if (index < 0 || head == nullptr)
            return -1;
        
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            if (current->next == nullptr)
                return -1;
            current = current->next;
        }
        
        return current->data;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        
        if (head == nullptr) {
            head = newNode;
            return;
        }
        
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        
        current->next = newNode;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0)
            return;
        
        if (index == 0) {
            addAtHead(val);
            return;
        }
        
        Node* newNode = new Node(val);
        Node* current = head;
        Node* prev = nullptr;
        
        for (int i = 0; i < index; ++i) {
            if (current == nullptr)
                return;
            prev = current;
            current = current->next;
        }
        
        newNode->next = current;
        prev->next = newNode;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || head == nullptr)
            return;
        
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        
        Node* current = head;
        Node* prev = nullptr;
        
        for (int i = 0; i < index; ++i) {
            if (current == nullptr)
                return;
            prev = current;
            current = current->next;
        }
        
        if (current == nullptr)
            return;
        
        prev->next = current->next;
        delete current;
    }
};

int main() {
    MyLinkedList linkedList;
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        string operation;
        cin >> operation;
        
        if (operation == "get") {
            int index;
            cin >> index;
            int result = linkedList.get(index);
            cout << result << " ";
        } else if (operation == "addAtHead") {
            int val;
            cin >> val;
            linkedList.addAtHead(val);
        } else if (operation == "addAtTail") {
            int val;
            cin >> val;
            linkedList.addAtTail(val);
        } else if (operation == "addAtIndex") {
            int index, val;
            cin >> index >> val;
            linkedList.addAtIndex(index, val);
        } else if (operation == "deleteAtIndex") {
            int index;
            cin >> index;
            linkedList.deleteAtIndex(index);
        }
    }
    
    return 0;
}