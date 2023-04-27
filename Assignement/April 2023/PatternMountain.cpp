#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int i,j;

    for(i=1; i<=n; i++){
        for(j=1; j<=i; j++){
            cout<<j<<'\t';
        }
        for(j=2; j<=2*(n-i)-1; j++){
            cout<<' '<<'\t';
        }
        for(j=i; j>1; j--){
            if(j!=n)
                cout<<j<<'\t';
        }
        cout<<endl;
    }

    return 0;
}