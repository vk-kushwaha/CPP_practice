#include<iostream>
using namespace std;

 int main(){
     int n,i;
     cout<<" Enter any number \n";
     cin>>n;

     for( i=2; i<n; i++){

        if(n%i==0)
        {
            cout<<" It is not  a prime Number "<<endl;
    
            break;
        }
     } if (n==i){
       cout<<"  It is a prime Number ";
     }     
        
 }