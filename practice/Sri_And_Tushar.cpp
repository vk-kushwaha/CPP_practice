#include <iostream>
#include <vector>

using namespace std;

bool isSameCount(vector<int>& nums) {
    int n = nums.size();

    // Check for global inversions that are not local inversions
    for (int i = 0; i < n - 1; ++i) {
        if (nums[i] > nums[i + 1]) {
            if (nums[i] != i + 1 || nums[i + 1] != i) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    if (isSameCount(nums)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
