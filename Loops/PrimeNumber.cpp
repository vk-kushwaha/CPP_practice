#include<iostream>
using namespace std;

 int main(){
     int n;
     cout<<" Enter any number \n";
     cin>>n;
        bool isprime=true;
     for(int i=2; i<n; i++){

        if(n%i==0)
        {
            isprime=false;
            break;
        }
     } if (isprime){
       cout<<"  It is a prime Number ";
     } else
     cout<<" it is not a prime number";    
        
 }