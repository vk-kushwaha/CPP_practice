#include<iostream>
#include<cstring>
using namespace std;
string str;
string Add2String(string str1, string str2){
     str= str1+" "+str2;
    int n=str.length();
   // cout<<"Length of New String = "<<n-1<<endl;
    return str;
}


int main(){
    string str1,str2;

    cout<<"Enter two string to merge them\n";
    cin>>str1>>str2;

    cout<<"\nNew String is = "<<Add2String(str1,str2);
    cout<<"\nLength of New String = "<<str.length()-1<<" Charactors";
}