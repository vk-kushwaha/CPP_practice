#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void SiftAtEnd(int* arr,int idx,int n, int target){

    if(idx==n-1)
    return;

    if(arr[idx]==target){
        swap(arr[idx],arr[idx+1]);
        
    }

    SiftAtEnd(arr,idx+1,n,target);


}
int main(){

    int n, target;
    cin>>n>>target;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    SiftAtEnd(arr,0,n ,target);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    


 return 0;
}