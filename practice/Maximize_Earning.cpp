#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int deleteAndEarn(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    // Create a frequency map to count the occurrences of each number
    unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }

    // Determine the maximum value in the array
    int maxVal = 0;
    for (const auto& entry : freqMap) {
        maxVal = max(maxVal, entry.first);
    }

    // Initialize an array to store the maximum points for each value
    vector<int> dp(maxVal + 1, 0);

    // Dynamic programming to calculate the maximum points
    for (int i = 1; i <= maxVal; ++i) {
        dp[i] = max(dp[i - 1], (freqMap.count(i) ? dp[i - 2] + i * freqMap[i] : 0));
    }

    return dp[maxVal];
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = deleteAndEarn(nums);
    cout << result << endl;

    return 0;
}
