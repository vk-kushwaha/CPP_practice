#include <iostream>
using namespace std;

class Queue
{

    int *arr;
    int front, rear, capacity;

public:
    Queue(int cap)
    {

        arr = new int[cap];
        front = -1;
        rear = -1;
        capacity = cap;
    }

    void enqueue(int ele)
    {
        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = ele;
            return;
        }
        else if (rear == capacity - 1)
        {
            cout << " \nQueue is overflow";
        }

        arr[++rear] = ele;
    }

    void dequeue()
    {
        if (front == -1 && rear == -1)
        {
            cout << " \nQueue is under flow";
            return;
        }
        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }

    int getfront()
    {
        return arr[front];
    }

    bool empty(){
        if(front ==-1 && rear == -1)
        return true;

        return false;
    }
};

int main()
{
    int size;
    cout<< "Enter the size of Queue\n";
    cin>> size;
    Queue q1(size);

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);

    // cout << q1.getfront() << endl;
    // q1.dequeue();
    // cout << q1.getfront() << endl;
    // q1.dequeue();
    // cout << q1.getfront() << endl;
    // q1.dequeue();
    // cout << q1.getfront() << endl;
    // q1.dequeue();
    // cout << q1.getfront() << endl;
    // q1.dequeue();

    while(!q1.empty()){
        cout << q1.getfront() << endl;
        q1.dequeue();
    }
    q1.dequeue();    // this will show msg as Q is under flow.


    return 0;
}