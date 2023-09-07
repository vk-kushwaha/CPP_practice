#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;
void ReverseStack(stack<int>&st)
{
    stack<int>tmpst;
    
    while(!st.empty())
    {
        int topEle= st.top();
        st.pop();
        tmpst.push(topEle);
    }
    st=tmpst;
}


void display(stack<int>st)
{
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}
using namespace std;
int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    cout<<"Before Reverse Stack\n";
    display(st);

    ReverseStack(st);

    cout<<"After Reverse Stack\n";

    display(st);


 return 0;
}