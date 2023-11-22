#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> count(6, 0);

    for (int i = 0; i < n; i++) {
        if (arr[i] == 4) {
            count[0]++;
        } else if (arr[i] == 8 && count[0] > count[1]) {
            count[1]++;
        } else if (arr[i] == 15 && count[1] > count[2]) {
            count[2]++;
        } else if (arr[i] == 16 && count[2] > count[3]) {
            count[3]++;
        } else if (arr[i] == 23 && count[3] > count[4]) {
            count[4]++;
        } else if (arr[i] == 42 && count[4] > count[5]) {
            count[5]++;
        }
    }

    int elementsToRemove = n - count[5] * 6;

    cout << elementsToRemove << endl;

    return 0;
}