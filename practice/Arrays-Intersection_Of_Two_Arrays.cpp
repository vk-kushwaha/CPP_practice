#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find intersection of two arrays
vector<int> findIntersection(const vector<int>& arr1, const vector<int>& arr2) {
    unordered_map<int, int> countMap;
    vector<int> intersection;

    // Count occurrences of elements in the first array
    for (int num : arr1) {
        countMap[num]++;
    }

    // Check elements in the second array against the countMap
    for (int num : arr2) {
        if (countMap.find(num) != countMap.end() && countMap[num] > 0) {
            intersection.push_back(num);
            countMap[num]--;
        }
    }

    return intersection;
}

int main() {
    int N;
    cin >> N;

    // Input for the first array
    vector<int> arr1(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr1[i];
    }

    // Input for the second array
    vector<int> arr2(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr2[i];
    }

    // Find intersection
    vector<int> result = findIntersection(arr1, arr2);

    // Sort the result vector
    sort(result.begin(), result.end());

    // Print the result
    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
