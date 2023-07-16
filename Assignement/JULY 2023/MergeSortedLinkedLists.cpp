#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to merge two sorted linked lists
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    ListNode *mergedList = nullptr;
    ListNode *tail = nullptr;

    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            if (!mergedList)
            {
                mergedList = l1;
                tail = l1;
            }
            else
            {
                tail->next = l1;
                tail = l1;
            }
            l1 = l1->next;
        }
        else
        {
            if (!mergedList)
            {
                mergedList = l2;
                tail = l2;
            }
            else
            {
                tail->next = l2;
                tail = l2;
            }
            l2 = l2->next;
        }
    }

    if (l1)
        tail->next = l1;
    else
        tail->next = l2;

    return mergedList;
}

// Function to print the linked list
void printLinkedList(ListNode *head)
{
    ListNode *current = head;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N1, N2;
        cin >> N1;

        ListNode *list1 = nullptr;
        ListNode *tail1 = nullptr;

        // Input for list1
        for (int i = 0; i < N1; i++)
        {
            int value;
            cin >> value;
            ListNode *newNode = new ListNode(value);
            if (!list1)
            {
                list1 = newNode;
                tail1 = newNode;
            }
            else
            {
                tail1->next = newNode;
                tail1 = newNode;
            }
        }

        cin >> N2;

        ListNode *list2 = nullptr;
        ListNode *tail2 = nullptr;

        // Input for list2
        for (int i = 0; i < N2; i++)
        {
            int value;
            cin >> value;
            ListNode *newNode = new ListNode(value);
            if (!list2)
            {
                list2 = newNode;
                tail2 = newNode;
            }
            else
            {
                tail2->next = newNode;
                tail2 = newNode;
            }
        }

        // Merge and print the lists
        ListNode *mergedList = mergeTwoLists(list1, list2);
        printLinkedList(mergedList);

        // Free allocated memory to avoid memory leaks
        while (mergedList)
        {
            ListNode *temp = mergedList;
            mergedList = mergedList->next;
            delete temp;
        }
    }

    return 0;
}