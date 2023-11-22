#include <iostream>
#include <vector>

using namespace std;

vector<int> selflessProducts(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefixProduct(n, 1);
    vector<int> suffixProduct(n, 1);

    // Calculate prefix products
    for (int i = 1; i < n; ++i) {
        prefixProduct[i] = prefixProduct[i - 1] * nums[i - 1];
    }

    // Calculate suffix products
    for (int i = n - 2; i >= 0; --i) {
        suffixProduct[i] = suffixProduct[i + 1] * nums[i + 1];
    }

    // Calculate selfless products
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        result[i] = prefixProduct[i] * suffixProduct[i];
    }

    return result;
}

int main() {
    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    vector<int> result = selflessProducts(nums);

    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }

    return 0;
}
