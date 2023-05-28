#include<iostream>
using namespace std;
int main(){

int a[100],b[100],n,m, count=0;
cin>>n>>m;

for(int i=0; i<n; i++){
    cin>>a[i];
}


for(int i=0; i<m; i++){
    cin>>b[i];
}

for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){

        if(b[i]>=a[j])
         count++;
    }
    
    cout<<count<<" ";
    count=0;
}

}