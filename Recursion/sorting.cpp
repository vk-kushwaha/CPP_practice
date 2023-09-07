#include<iostream>
using namespace std;

 bool Sorted(int *arr, int idx,int n){

    if(idx==n-1)
    return true;
    if(arr[idx]>arr[idx+1])
    return false;

    return Sorted(arr, idx+1, n);

}

int main(){

    int arr[]={1,2,3,4,5,6,7,8,9},n=9;

    if(Sorted(arr,0,n))
    cout<<"Sorted Array\n";
    else
    cout<<"Not Sorted Array\n";
 
}