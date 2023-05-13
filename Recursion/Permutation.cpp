#include <iostream>
#include<cstring>
using namespace std;

void permutation(char str[],int pos)
{
	if(pos==strlen(str))
	{
		cout<<str<<endl;
		return;
	}


	for(int i=pos;i<strlen(str);i++)
	{
		
		
		int tmp=str[pos];
		str[pos]=str[i];
		str[i]=tmp;

		permutation(str,pos+1);
        tmp=str[pos];
		str[pos]=str[i];
		str[i]=tmp;
	}

}

int main()
{
	char str[]="abc";
	permutation(str,0);
}