#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> dp(26, vector<long long>(2, -1));

// Function to count the number of valid n-digit integers
long long countValidIntegers(int n, bool prevB) {
    if (n == 0) return 1;
    if (dp[n][prevB] != -1) return dp[n][prevB];

    long long count = 0;

    if (prevB) {
        count = countValidIntegers(n - 1, false);
    } else {
        count = countValidIntegers(n - 1, false) + countValidIntegers(n - 1, true);
    }

    dp[n][prevB] = count;
    return count;
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        int n;
        cin >> n;
        long long result = countValidIntegers(n, false) + countValidIntegers(n, true);
        cout << "#" << i << " : " << result << endl;
    }

    return 0;
}
