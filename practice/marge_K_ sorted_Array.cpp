#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to store the elements along with their array index and position
struct Element {
    int value;
    int arrayIndex;
    int position;

    Element(int val, int arrIdx, int pos) : value(val), arrayIndex(arrIdx), position(pos) {}

    // Overloading the comparison operator for the min-heap
    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

// Function to merge K sorted arrays
vector<int> mergeSortedArrays(vector<vector<int>>& arrays, int K, int N) {
    vector<int> result;
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;

    // Initialize the min-heap with the first element from each array
    for (int i = 0; i < K; ++i) {
        if (!arrays[i].empty()) {
            minHeap.push(Element(arrays[i][0], i, 0));
        }
    }

    // Continue until the min-heap is not empty
    while (!minHeap.empty()) {
        // Get the smallest element from the min-heap
        Element minElement = minHeap.top();
        minHeap.pop();

        // Add the smallest element to the result
        result.push_back(minElement.value);

        // If there is a next element in the same array, add it to the min-heap
        if (minElement.position + 1 < N) {
            minHeap.push(Element(arrays[minElement.arrayIndex][minElement.position + 1], minElement.arrayIndex, minElement.position + 1));
        }
    }

    return result;
}

int main() {
    int K, N;
    cin >> K >> N;

    // Read the K sorted arrays
    vector<vector<int>> arrays(K, vector<int>(N));
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arrays[i][j];
        }
    }

    // Merge and print the sorted array using the function
    vector<int> sortedArray = mergeSortedArrays(arrays, K, N);
    for (int num : sortedArray) {
        cout << num << " ";
    }

    return 0;
}
