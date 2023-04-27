#include<iostream>
using namespace std;
int main(){
    int n=3 ;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<" ";
        }
        for(int j=i; j<=i; j++){
            cout<<"@";
        }
        int spaces= 2*(n-i);  // to print spcaes between stars.
        for(int j= 1; j<= spaces; j++){
            cout<<" ";
        }
        for(int j=i; j<=i; j++){
            cout<<" ";
        }
        for(int j=i; j<=i; j++){
            cout<<"@";
        }
        cout<<endl;
    }
    for(int i=n; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<" ";
        }
        for(int j=i; j<=i; j++){
            cout<<"@";
        }
        int spaces= 2*(n-i);  // to prit spcaes between stars.
        for(int j= 1; j<= spaces; j++){
            cout<<" ";
        }
        for(int j=i; j<=i; j++){
            cout<<" ";
        }
        for(int j=i; j<=i; j++){
            cout<<"@";
        }
        cout<<endl;
    }
     
}