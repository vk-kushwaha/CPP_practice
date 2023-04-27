#include<iostream>
using namespace std;

 int Add(int a, int b){
 	int sum=a+b;
 	return sum;
 }

 int Substract(int a, int b){
 	int sub=a-b;
 	return sub;
 }
 int Multiply(int a, int b){
 	int mul=a*b;
 	return mul;
 }
 int Divide(int a, int b){
 	int div=a/b;
 	return div;
 }
int main(){
 int n,a,b;
	cout<<"\nPress 1 to Add numbers";
	cout<<"\nPress 2 to Substract numbers";
	cout<<"\nPress 3 to Multiply numbers";
	cout<<"\nPress 4 to Divide numbers\n";
	cin>>n;

switch(n){


case 1:
	cout<<"Enter Two number to Add\n";
 	 cin>>a>>b;
	cout<<"Sum of Input is = "<<Add(a,b);
	break;
 case 2:
 	cout<<"Enter Two number to Substract\n";
 	cin>>a>>b;
	cout<<"Substract of Input is = "<<Substract(a,b);
	break;
case 3:
	cout<<"Enter Two number to Multiply\n";
 	 cin>>a>>b;
	cout<<"Multiply of Input is = "<<Multiply(a,b);
	break;
case 4:
	cout<<"Enter Two number to Divide\n";
 	 cin>>a>>b;
	cout<<"Division of Input is = "<<Divide(a,b);
	break;

default :
	cout<<" incorrect input";
}
}