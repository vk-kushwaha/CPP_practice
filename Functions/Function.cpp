#include<iostream>
using namespace std;
 
 int Add(int a, int b){
 	int sum= a+b;
 	return sum;
 }

 int MultiplyNo(int a, int b){
 	int Pdt= a*b;
 	return Pdt;
 }
  int CompNos(int a, int b,int c){
  	if(a>=b && a>=b)
  		return a;
  	else if(b>=c && b>=a)
  		return b;
  	else 
  			return c;

  	 }
 int main(){
 	
 	cout<<Add(10,20)<<endl;
 	cout<<endl<<MultiplyNo(3,6)<<endl;
 	cout<<endl<<CompNos(100,25,9)<<endl;

 }