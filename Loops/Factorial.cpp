#include<iostream>
using namespace std;
int main(){

    int n,fact=1;

    cout<< "Enter any number to get factorial";
    cin>>n;

    for(int i=1; i<=n; i++){

         fact=fact*i;
        
    }
    cout<<"Factorial of given number is = "<<fact;
    return 0;
}