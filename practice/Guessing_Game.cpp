#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCost(int n) {
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int len = 2; len <= n; len++) {
        for (int start = 1; start <= n - len + 1; start++) {
            int end = start + len - 1;
            int minCost = INT_MAX;

            for (int guess = start; guess <= end; guess++) {
                int cost = guess + max(dp[start][guess - 1], dp[guess + 1][end]);
                minCost = min(minCost, cost);
            }

            dp[start][end] = minCost;
        }
    }

    return dp[1][n];
}

int main() {
    int n;
    cin >> n;

    int result = minCost(n);
    cout << result << endl;

    return 0;
}
