#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();

    if (n <= 1) {
        return 0;
    }

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < n; ++i) {
        // Update the minimum price if a lower price is encountered
        minPrice = min(minPrice, prices[i]);

        // Update the maximum profit if selling at the current day gives a higher profit
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }

    return maxProfit;
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
