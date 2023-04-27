#include<iostream>
using namespace std;
int main(){
 int n;
	cin>>n;

int sum=0;
while(n!=0) {     //we can use while(n)
int unitDigit=n%10;
sum+=unitDigit;
n=n/10;
}

cout<<"Sum of Digit ="<<sum;
}