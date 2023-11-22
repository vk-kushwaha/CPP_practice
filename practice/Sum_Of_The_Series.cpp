/*Write a program to find the sum of the given series 1+2+3+ . . . . . .(N terms) 

Example 1:

Input:
N = 1
Output: 1
Explanation: For n = 1, sum will be 1.
Example 2:

Input:
N = 5
Output: 15
Explanation: For n = 5, sum will be 15.
1 + 2 + 3 + 4 + 5 = 15.*/ 


#include<iostream>
using namespace std;


	class Solution{
public:
	// function to return sum of  1, 2, ... n
	long long seriesSum(int N) {
	long long sum = (static_cast<long long>(N) * (N + 1)) / 2;
        return sum;
    }
    
};

int main(){
	int n;
	cin>>n;

	  int seriesSum(n);

	 cout<<seriesSum;


}