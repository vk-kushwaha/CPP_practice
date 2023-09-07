#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int bsearch(int *arr, int st, int en, int Target){
    if(st>en)
    return -1;

    int mid= (st+en)/2;
    if(Target== arr[mid]){
        return mid;
    }
    else if(Target > mid){
        st= mid+1;
    }
    else
        en=mid-1;

        return bsearch(arr,st,en,Target);
}
int main(){
int n,Target;
cin>>n>>Target;
int arr[n];

for(int i=0; i<n; i++){

    cin>>arr[i]; 
}

    cout<<bsearch(arr,0,n-1,Target);
 return 0;
}