#include<iostream>
#include<queue>
using namespace std;

void Display(queue<int>q){
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
}
int main()
{
    queue<int>q;

    q.push(10);
    q.push(20);
    q.push(30);

   // cout<<q.front()<<endl;

    Display(q);
 
    return 0;
}