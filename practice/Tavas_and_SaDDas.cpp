#include <iostream>
using namespace std;

int main(){


    int n,k,m;
    k = 0;
    m=1;
    cin>>n;
    while(n){
        if(n%10==4){
            k+=m;
        }
        else{
            k+=2*m;
        }
        m*=2;
        n/=10;
    }
    cout<<k;    
}