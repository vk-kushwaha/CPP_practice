#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

void StockSpan(int * price, int N){
    stack<int> st;
    int span[N];

    for (int  i = 0; i < N; i++)
    {
        while(!st.empty() && price[i]>price[st.top()])
        {
            st.pop();
        }
        if(st.empty())
        span[i]=i+1;
        else
        span[i]= i - st.top();
        st.push(i);
    }

    for (int i = 0; i < N; i++)
    {
        cout<<span[i]<<" ";
    }
    cout<<"END";
    
    
}
int main(){
 int N;
 cin>>N;
 int price[N];

 for (int i = 0; i < N; i++)
 {
    cin>>price[i];
 }

 StockSpan(price, N);
 

 return 0;
}