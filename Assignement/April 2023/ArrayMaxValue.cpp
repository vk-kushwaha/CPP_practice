#include<iostream>
using namespace std;
int main(){

	int arr[5];
	int n= (sizeof(arr)/sizeof(arr[0]));
	
	for(int i=0; i<n; i++){
	cin>>arr[i];
	}	

int Max=INT_MIN;

for(int i=0; i<n; i++){

	if(Max<arr[i])
		Max=arr[i];
	}

	cout<<Max;

	return 0;
}