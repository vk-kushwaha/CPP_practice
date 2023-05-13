#include<iostream>
using namespace std;
int main(){

    int n,k=1;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if(i==0)
           cout<<"1";
           else if (j==0 || j==i)
           cout<<i;
           else
           cout<<"0";
        }
        cout<<endl;
    }
    
}