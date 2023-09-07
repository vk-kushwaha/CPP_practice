#include <iostream>
#include <vector>
using namespace std;

int countSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> prefixSum(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + (nums[i] % 2);
    }

    int left = 0, right = 0;
    int NiceSubarray = 0;

    while (right < n) {
        if (prefixSum[right + 1] - prefixSum[left] == k) {
            int leftCount = 0;
            while (prefixSum[left] % 2 == 0) {
                leftCount++;
                left++;
            }
            int rightCount = 0;
            while (prefixSum[right + 1] % 2 == 0) {
                rightCount++;
                right++;
            }
            NiceSubarray += (leftCount + 1) * (rightCount + 1);
            left++;
        }
        right++;
    }

    return NiceSubarray;
}

int main() {
    int N, k;
    cin >> N >> k;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int NiceSubarray = countSubarray(nums, k);
    cout << NiceSubarray << endl;

    return 0;
}
