#include<iostream>
using namespace std;
int main()
{
int arr[]={10,25,5,33,10,22,12,40,20,2};
int n=10;

int minNo=INT_MAX;
int MaxNo=INT_MIN;

for(int i=0; i<n;i++)

{
if(minNo>arr[i])
minNo=arr[i];

if(MaxNo<arr[i])
MaxNo=arr[i];
}


//for(int i=0; i<n; i++)

cout<<" \n min number = "<<minNo<<endl;
cout<<" \n Max Number ="<<MaxNo<<endl;

cout<<"\n Given array is = ";

for(int i=0; i<n;i++)
{
    cout<<arr[i]<<" ";
}
}