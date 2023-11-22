#include <iostream>
#include <vector>

using namespace std;

int findInMountainArray(int target, vector<int>& arr) {
    int n = arr.size();

    // Find the peak element
    int peakIndex = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            peakIndex = i;
            break;
        }
    }

    // Perform binary search on the increasing part
    int left = 0, right = peakIndex;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Perform binary search on the decreasing part
    left = peakIndex, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    int N, target;
    cin >> N >> target;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int result = findInMountainArray(target, arr);
    cout << result << endl;

    return 0;
}
