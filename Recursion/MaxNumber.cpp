#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int MaxNumber(int * arr, int n){
    if(n==0)
    return -1;
    MaxNumber(arr,n-1);
    int ans= max(arr[n-1], arr[n-2]);
    return ans;
}
int main(){

int n;
    cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<< MaxNumber(arr, n)<<endl;

 return 0;
}