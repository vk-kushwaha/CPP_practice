#include <iostream>
#include <vector>

using namespace std;

string NonDecreasing(vector<int>& nums) {
    int n = nums.size();
    int count = 0; // Count of elements violating non-decreasing order

    for (int i = 0; i < n - 1; ++i) {
        if (nums[i] > nums[i + 1]) {
            count++;
            if (count > 1) {
                return "NO";
            }

            // Check if modifying the current or next element can fix the violation
            if (i > 0 && nums[i - 1] > nums[i + 1]) {
                nums[i + 1] = nums[i];
            } else {
                nums[i] = nums[i + 1];
            }
        }
    }

    return "YES";
}

int main() {
    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    string result = NonDecreasing(nums);
    cout << result << endl;

    return 0;
}
