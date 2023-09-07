#include <iostream>
using namespace std;

int TotalWays(int n){
    if(n==0)
    return 1;
    
    if(n<0)
    return 0;
    
    int ans= TotalWays(n-1)+ TotalWays(n-2)+ TotalWays(n-3);
    return ans;
}
int main() {
	
	int k;
	cin>>k;
	
	cout<<TotalWays(k);
	return 0;
}
