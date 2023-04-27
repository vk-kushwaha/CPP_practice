#include<iostream>
using namespace std;

void  ODDEVEN(int n)
{
	if (n%2==0)
		cout<<n<<" is an Even Number\n";
	else
		cout<<n<<" is an Odd Number\n";

}

int LargeNo(int a, int b, int c){
	if (a>=b && a>=c)
		return a;
	else if(b>=c && b>=a)
		return b;
	else
		return c;
}



int main(){


	int n,i=1,a,b,c;

	while(i==1)
	{
	cout<<"\n Enter any Number to check Even/Odd\n";

	cin>>n;

	ODDEVEN(n);

	cout<<"\nPress 1 to check again or Press any to exit\n";
	cin>>i;
}
	cout<<"Enter three integer numbers\n";
	cin>>a>>b>>c;
	//LargeNo(a,b,c);
	cout<<"Largest Number is = "<<LargeNo(a, b, c);

}