#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> a(n);

    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> mp;
    vector<int> ansv;

    for (i = n - 1; i >= 0; i--) {
        if (mp.find(a[i]) == mp.end()) {
            ansv.push_back(a[i]);
            mp[a[i]] = 1;
        }
    }

    reverse(ansv.begin(), ansv.end());

    for (int x : ansv) {
        cout << x << endl;
    }

    return 0;
}
