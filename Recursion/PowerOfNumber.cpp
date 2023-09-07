#include<iostream>
using namespace std;

int PowerOfTwo(int n){
    if(n==1)
    return 2;

     int ans=2*PowerOfTwo(n-1);
     return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<PowerOfTwo(n);

 
    return 0;
}