#include<iostream>
using namespace std;

int BinarySearch(int *arr,int idx, int target, int n){

    if(idx==n)
    return -1;
    if(arr[idx]==target)
    return idx;

    int ans= BinarySearch(arr,idx+1,target,n);
    return ans;

}
int main(){
    int arr[]={1,2,2,2,3,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=3;

    cout<<BinarySearch(arr,0,target,n);
}