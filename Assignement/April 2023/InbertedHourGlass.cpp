#include<iostream>
using namespace std;
int main(){
	int n,k=0;
	cin>>n;

for(int i=0; i<=n;i++){
	for(int j=0; j<=i; j++){
		cout<<n-j<<" ";
		}
	for(int j=1; j<(4*(n-i))-1; j++){
		cout<<" ";
	}
	for(int j=i; j>=0; j--){
		if(j!=n)
		cout<<n-j<<" ";
	}
	cout<<endl;
	}
	for(int i=n-1; i>=0;i--){
	for(int j=0; j<=i; j++){
		cout<<n-j<<" ";
		}
	for(int j=1; j<(4*(n-i))-1; j++){
		cout<<" ";
	}
	for(int j=i; j>=0; j--){
		cout<<n-j<<" ";
	}

	cout<<endl;
	}
}