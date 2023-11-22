#include <iostream>
#include <vector>

using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();

    if (n <= 1) {
        return n;
    }

    vector<int> lengths(n, 1);  // lengths[i] represents the length of the LIS ending at index i
    vector<int> counts(n, 1);   // counts[i] represents the number of LIS ending at index i

    int maxLength = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                if (lengths[j] + 1 > lengths[i]) {
                    lengths[i] = lengths[j] + 1;
                    counts[i] = counts[j];
                } else if (lengths[j] + 1 == lengths[i]) {
                    counts[i] += counts[j];
                }
            }
        }

        maxLength = max(maxLength, lengths[i]);
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        if (lengths[i] == maxLength) {
            result += counts[i];
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = findNumberOfLIS(nums);
    cout << result << endl;

    return 0;
}
