#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int  NaturalNumber(int n){
    if(n==1)
    return 1;
    int ans=0;
    ans = n+(NaturalNumber(n-1));
    return ans;
    
}
int main(){
    int n=10;
    

   cout<< NaturalNumber(n)<<endl;


 return 0;
}