#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), greater<int>());

    cout << arr[k - 1] << endl;

    return 0;
}
