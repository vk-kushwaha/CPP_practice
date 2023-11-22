#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int totalTimeRequired(vector<int>& callingOrder, vector<int>& idealOrder) {
    int n = callingOrder.size();
    int totalTime = 0;

    // Map the index of each process in the ideal order
    unordered_map<int, int> idealIndex;
    for (int i = 0; i < n; ++i) {
        idealIndex[idealOrder[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        // Find the index of the process in the calling order
        int currentIndex = idealIndex[callingOrder[i]];

        // Rotate the calling order to match the current element of the ideal order
        while (callingOrder[currentIndex] != idealOrder[i]) {
            swap(callingOrder[currentIndex], callingOrder[(currentIndex + 1) % n]);

            totalTime++; // Increment the total time for rotation
        }

        totalTime++; // Increment the total time for executing the current process
    }

    return totalTime;
}

int main() {
    int n;
    cin >> n;

    vector<int> callingOrder(n);
    for (int i = 0; i < n; ++i) {
        cin >> callingOrder[i];
    }

    vector<int> idealOrder(n);
    for (int i = 0; i < n; ++i) {
        cin >> idealOrder[i];
    }

    int result = totalTimeRequired(callingOrder, idealOrder);
    cout << result << endl;

    return 0;
}
