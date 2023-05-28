#include<iostream>
using namespace std;

bool SortedArray(int*arr, int cindx, int n)
{

	if(cindx==n-1){
		return true;
	}

	if(arr[cindx]>arr[cindx+1])
		return false;
	
	return SortedArray(arr,cindx+1,n);

}

int main(){

	int arr[]={1,2,3,3,5,6};
	int n=6;
	if(SortedArray(arr,0,n))
		cout<<"Sorted";
	else 
		cout<<"Unsorted";
	
}