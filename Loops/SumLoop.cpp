#include<iostream>
using namespace std;
int main(){
int i=0,n;

cout<<"Enter count of number to be enter\n ";
cin>>n;
int sum=0;
cout<<"Enter any "<<n<<" Numbers to sum\n";
while(i<n)
{
int no;
cin>>no;

sum=sum+no;
i++;
}
cout<<"Sum of given Number  ="<<sum; 


}