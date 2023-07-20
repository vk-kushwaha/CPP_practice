#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dp[10005]; // static array declaration.

int fib(int n)
{ // recursion function.
    if (n <= 1)
    {
        return n;
    }

    if (dp[n] != -1) // check if value is already calculated.
    {
        return dp[n];
    }
    int OP1 = fib(n - 1); // Recursion recalling
    int OP2 = fib(n - 2); // Recursion recalling

    int ans = OP1 + OP2;

    return dp[n] = ans; // store and in array
}

     int fib1(int n){ // Itterative way of calculation of Fibbonacci Number.

        dp[0]=0;
        dp[1]=1;

        for(int i=2; i<=n; i++){
            dp[i]= dp[i-1]+ dp[i-2];
        }

        return dp[n];
     }
int main()
{
    int n;
    cin >> n;

   
    memset(dp, -1, sizeof(dp)); // initialisation of array by -1.

    cout << fib(n) << endl;

    memset (dp,-1, sizeof(dp));

    cout<<fib1(n)<<endl;

    return 0;
}