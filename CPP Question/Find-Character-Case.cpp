#include<iostream>
using namespace std;

int main (){


	char a;
	cin>>a;

	if(a<='Z' && a>='A'){
		cout<<"1";
	} else if ((a<='z' && a>='a')){
		cout<<"0";
	}else
	cout<<"-1";
}