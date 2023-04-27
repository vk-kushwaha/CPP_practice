#include<iostream>
using namespace std;
int main(){
 int n;

 cout<<"Enter number or integers \n";
	cin>>n;

int sum=0,no;

cout<<"Enter any "<<n<<" Number to Add \n";
for(int i=0; i<n;i++)

{cin>>no;
  sum=sum+no;
}
cout<<"sum of  Given Numbers are = "<<sum;
}