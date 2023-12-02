#include <iostream>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        priority_queue<int> maxHeap;  // Max heap for the smaller half
        priority_queue<int, vector<int>, greater<int>> minHeap;  // Min heap for the larger half

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;

            // Insert into heaps
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }

            // Balance the heaps
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            // Calculate and print the median
            if (i % 2 == 0) {
                cout << maxHeap.top() << " ";
            } else {
                cout << (maxHeap.top() + minHeap.top()) / 2 << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
