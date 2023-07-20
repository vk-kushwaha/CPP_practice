#include <iostream>
#include <bits/stdtr1c++.h>
using namespace std;
int OP1 = INT_MAX, OP2 = INT_MAX;

int dp[100010];
int solve(int *height, int x)
{
    if (x <= 0)
    {
        return 0;
    }
    if (dp[x] != -1)
    {
        return dp[x];
    }

    if (x - 1 >= 0)
        OP1 = solve(height, x - 1) + abs(height[x] - height[x - 1]);

    if (x - 2 >= 0)
        OP2 = solve(height, x - 2) + abs(height[x] - height[x - 2]);

    int ans = min(OP2, OP1);
    return dp[x] = ans;
}

// Second recursive method to solve this problem.

int solve2(int *height, int x, int n)
{

    if (x == n)
        return 0;

    if (dp[x] != -1)
    {
        return dp[x];
    }
    if (x + 1 <= 0)
        OP1 = solve2(height, x + 1, n) + abs(height[x] - height[x - 1]);

    if (x + 2 <= 0)
        OP2 = solve2(height, x + 2, n) + abs(height[x] - height[x - 2]);

    int ans = min(OP2, OP1);
    return dp[x] = ans;
}
int main()
{
    int n;
    cin >> n;
    int height[n];
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(height, n - 1) << endl;
    memset(dp, -1, sizeof(dp));
    cout << solve2(height, 0, n - 1) << endl;

    return 0;
}