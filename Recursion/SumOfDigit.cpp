#include<iostream>
using namespace std;

int SumOfDigit(int n){

    if(n<10){
        return n;
    }
    
    int ans= n%10 + SumOfDigit(n/10);
    
    
    return ans;
}
int main()
{
 int n;
 cout<<"Enter NUmber\n";
 cin>>n;

 cout<<SumOfDigit(n);
    return 0;
}