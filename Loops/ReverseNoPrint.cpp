#include<iostream>
using namespace std;
int main(){
    int n;
    //cout<<"Enter any Number to Print revers order";
    cin>>n;
     int revNo=0;

    while(n)
    {
        int unitDigit= n%10;
        revNo=revNo*10+unitDigit;
        n=n/10;

    }
    cout<<revNo;

}