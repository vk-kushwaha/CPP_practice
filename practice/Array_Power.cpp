#include <iostream>
#include <vector>

using namespace std;

int countCombinations(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= target; i++) {
        for (int num : nums) {
            if (i >= num) {
                dp[i] += dp[i - num];
            }
        }
    }

    return dp[target];
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = countCombinations(nums, target);
    cout << result << endl;

    return 0;
}
