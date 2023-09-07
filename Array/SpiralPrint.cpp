#include<iostream>
using namespace std;

const int MAX=100;

void PrintSpiral(int arr[MAX][MAX], int m, int n){
	int top=0, bottom=m-1, left=0, right=n-1;

	while(top <= bottom && left <= right){
		for (int i = left; i <= right; i++)
		{
			cout<<arr[top][i]<<" ";
		}
		top++;
	

		for (int i = top; i <= bottom; i++)
		{
			cout<<arr[i][right]<<" ";
		}
		right--;

		if(top<=bottom){
			for (int i = right; i >=left; i--)
			{
				cout<<arr[bottom][i]<<" ";
			}
			bottom--;
		}

		if(left<=right){
			for (int i = bottom; i >= top; i--)
			{
				cout<<arr[i][left]<<" ";
			}
			left ++;
		}
	}
}


int main(){

	int m,n, arr[MAX][MAX];

	cin >>m>>n;

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){

			cin>>arr[i][j];

		}
	}


	PrintSpiral(arr,m,n);

	return 0;
}