#include<iostream>
using namespace std;
int main(){

	int n;

	cout<<"Enter Value of n \n";
	cin>>n;
	int k=1;

	if(n<10){
	for(int i=0; i<n; i++){
		
		for(int j=0; j<=i; j++){
			cout<<k;
			k++;
		}	
		k=1;

		for(int j=n-2;j>=i; j--)
			cout<<"*";
	cout<<endl;

	}
}else
	cout<<"Enter number below 10\n";
	
	return 0;
}
