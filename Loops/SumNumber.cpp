#include<iostream>
using namespace std;
int main(){
	int i,n;

	cout<<"Enter any integer number";
	cin>>n;
	
	bool isprime=true;
	for( i=2; i<n; i++)
		{
			for(int j=2;j<i; j++)
				{if (i%j==0)
					isprime=false;
					break;

				}

	} if(isprime)
		cout<<i<<" ";
}