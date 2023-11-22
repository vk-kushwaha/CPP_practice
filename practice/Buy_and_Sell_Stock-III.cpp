#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    
    if (n <= 1) {
        return 0;
    }

    // Create arrays to store the maximum profit with at most two transactions
    vector<int> profitFirst(n, 0);
    vector<int> profitSecond(n, 0);

    // Forward pass to calculate the maximum profit for the first transaction
    int minPrice = prices[0];
    for (int i = 1; i < n; ++i) {
        minPrice = min(minPrice, prices[i]);
        profitFirst[i] = max(profitFirst[i - 1], prices[i] - minPrice);
    }

    // Backward pass to calculate the maximum profit for the second transaction
    int maxPrice = prices[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        maxPrice = max(maxPrice, prices[i]);
        profitSecond[i] = max(profitSecond[i + 1], maxPrice - prices[i]);
    }

    // Calculate the maximum total profit by combining profits from the two transactions
    int maxTotalProfit = 0;
    for (int i = 0; i < n; ++i) {
        maxTotalProfit = max(maxTotalProfit, profitFirst[i] + profitSecond[i]);
    }

    return maxTotalProfit;
}

int main() {
    int N;
    cin >> N;

    vector<int> prices(N);
    for (int i = 0; i < N; ++i) {
        cin >> prices[i];
    }

    int result = maxProfit(prices);
    cout << result << endl;

    return 0;
}
