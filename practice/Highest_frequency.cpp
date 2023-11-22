#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int findMaxFrequencyNumber(const vector<int>& arr) {
    unordered_map<int, int> frequencyMap;

    int maxFrequency = 0;
    int maxFrequencyNumber = arr[0]; // Initialize with the first element

    // Traverse the array and update the frequency map
    for (int num : arr) {
        frequencyMap[num]++;

        // Update max frequency and corresponding number
        if (frequencyMap[num] > maxFrequency) {
            maxFrequency = frequencyMap[num];
            maxFrequencyNumber = num;
        }
    }

    return maxFrequencyNumber;
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);

    // Input array elements
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    // Find and print the number with the maximum frequency
    int result = findMaxFrequencyNumber(arr);
    cout << result << endl;

    return 0;
}
