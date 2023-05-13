/*Take the following as input.

A number (N1)
A number (N2)
Write a function which prints first N1 terms of the series 3n + 2 which are not multiples of N2.
*/
#include<iostream>
using namespace std;
void  Series(int N1, int N2){
for(int i=1; i<=N1; i++){
    int ans=3*i+2;
    if(ans%N2!=0)
   
    cout<<ans<<endl;
    
    else
    N1++;
    }
}
int main(){

    int N1,N2;

    cin>>N1>>N2;
    Series(N1, N2);

}