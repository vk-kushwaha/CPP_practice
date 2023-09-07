#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void FindOdd(int n){
    if(n==0){
        return ;
    }

    if( n%2!=0)
    cout<<n<<" ";
    FindOdd(n-1);
    
}

void FindEven(int n)
{
    if(n==0)
    return ;

    if(n%2==0)
    cout<<n<<" ";
    FindEven(n-1);
}

int main(){
    int n;
    cin>>n;

    cout<<"Odd NUmbers\n";
     FindOdd(n);
    cout<< "Even Number\n";
    FindEven(n);


 return 0;
}