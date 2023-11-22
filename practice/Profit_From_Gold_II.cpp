#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); ++i) {
        // If the current price is greater than the previous day's price, we can make a profit
        if (prices[i] > prices[i - 1]) {
            maxProfit += prices[i] - prices[i - 1];
        }
    }

    return maxProfit;
}

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    int result = maxProfit(prices);
    cout << result << endl;

    return 0;
}
