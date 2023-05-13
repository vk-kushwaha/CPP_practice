#include<iostream>
using namespace std;
int main(){

    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if(i%2!=0)
            {if(j==0 || j==i)
            cout<<"1";
            else
            cout<<"0";
            }
            else
            cout<<"1";
            
        }
        cout<<endl;
    }
    
}