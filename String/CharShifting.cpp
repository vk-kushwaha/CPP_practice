#include<iostream>
#include<cstring>
using	namespace std;

 void shift( char str[], int sp){
 		int n=strlen(str);
 			for(int i=n-1; i>=0; i--){
 				str[i+sp]=str[i];
 			}
 			n=strlen(str);
 			int i=n-sp, j=0;
 			while(i<n){
 				str[j]=str[i];
 				i++;
 				j++;
 			}
 			str[n-sp]='\0';
 			cout<<endl<<str;
}

int main(){

	char str[100]="Hello";

	shift(str, 3);
}
