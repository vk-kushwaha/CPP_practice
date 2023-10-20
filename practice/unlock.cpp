#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void KswapPermutation(int arr[], int n, int k) {
        vector<int> pos(n + 1);

        for (int i = 0; i < n; i++) {
            pos[arr[i]] = i;
        }

        for (int i = 0; i < n && k > 0; i++) {
            if (arr[i] == n - i) {
                continue;
            }

            int original_index = pos[n - i];

            pos[arr[i]] = original_index;
            pos[arr[original_index]] = i;

            std::swap(arr[i], arr[original_index]);

            k--;
        }
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution solution;
    solution.KswapPermutation(arr, n, k);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
