#include <iostream>
using namespace std;

class CircularQueue
{
    int *arr;
    int front, rear, size, capacity;

public:
    CircularQueue(int cap)
    {
        arr = new int[cap];
        capacity = cap;
        front = 0;
        rear = capacity - 1;
        size = 0;
    }
    void push(int ele)
    {
        if (size == capacity)
        {
            cout << "\nOverflow";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = ele;
        size++;
    }
    void pop()
    {
        if (size == 0)
        {
            cout << "Underflow!!";
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    bool empty()
    {
        if (size == 0)
            return true;

        return false;
    }

    bool isFull()
    {
        return size == capacity;
    }

    int getFront()
    {
        return arr[front];
    }
};

void Display(CircularQueue q1)
{
    while (!q1.empty())
    {
        cout << q1.getFront() << endl;
        q1.pop();
    }
    return;
}
int main()
{

    CircularQueue q1(5);

    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);
    q1.push(50);
    // q1.push(60);
    Display(q1);
    cout << endl
         << q1.getFront() << endl;
    return 0;
}