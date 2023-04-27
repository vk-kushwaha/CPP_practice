#include<iostream> //include file name
//#include<conio.h>
using namespace std;
int main()
{
	//clrscr();
	int a,b,c;
	cout<<"Enter any three  number->"; //C++ statement
	cin>>a>>b>>c;
	if(a>b)  //outer if
	
	{
	if(a>c)   //inner if
	{
	cout<<"A is greater";
	}
	else
	{
	cout<<" C is greater";
	}                   //inner if close
	}                                   //outer if close
	else           //outer if- else part
	{
	 if(b>c)
	 {
	 cout<<"B is greater";
	 }
	 else
	 {
	 cout<<" C is greater";
	 }
	}
	return 0;
	//getch();

}     //End of program
