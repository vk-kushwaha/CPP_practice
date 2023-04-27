#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;

	for(int i=0;i<=n;i++){
		 for(int j=1; j<=i; j++){

		 	if(j==i||j==1)
		 	cout<<i<<"	";
		 else
		 	cout<<"0"<<"	"	;
		}
			cout<<endl;
	}

}