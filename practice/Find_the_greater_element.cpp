#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<long long> nextGreaterElement(vector<long long>& nums) {
    long long n = nums.size();
    vector<long long> result(n, -1);
    stack<long long> s;

    for (long long i = 0; i < 2 * n; ++i) {
        long long index = i % n;

        while (!s.empty() && nums[index] > nums[s.top()]) {
            result[s.top()] = nums[index];
            s.pop();
        }

        if (i < n) {
            s.push(i);
        }
    }

    return result;
}

int main() {
    long long n;
    cin >> n;

    vector<long long> nums(n);
    for (long long i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<long long> result = nextGreaterElement(nums);

    for (long long i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }

    return 0;
}
