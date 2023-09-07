#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int minElementsToRemove(vector<int>& arr) {
    const int n = arr.size();
    vector<int> seq = {4, 8, 15, 16, 23, 42};
    stack<int> s;
    int removed = 0;

    for (int num : arr) {
        if (num == 4) {
            s.push(0);
        } else {
            while (!s.empty() && num != seq[s.top() + 1]) {
                // If the current element doesn't match the next number in the sequence,
                // check if it can be part of an existing subsequence by looking for its previous number.
                ++removed;
                s.pop();
            }

            if (!s.empty()) {
                ++s.top();
                if (s.top() == 5) {
                    // If we complete a subsequence, pop it from the stack.
                    s.pop();
                }
            } else {
                // If the element doesn't match any subsequence, increment the removed count.
                ++removed;
            }
        }
    }

    // The remaining elements in the stack represent the unmatched subsequences.
    removed += s.size() * 6;

    return removed;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int minToRemove = minElementsToRemove(arr);
    cout << minToRemove << endl;

    return 0;
}
