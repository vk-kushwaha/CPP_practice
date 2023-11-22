#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int Q, k;
    cin >> Q >> k;

    priority_queue<long long, vector<long long>, greater<long long>> distances;

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int x, y;
            cin >> x >> y;
            long long dist = (long long)x * x + (long long)y * y;
            distances.push(dist);
        } else {
            vector<long long> temp;

            // Pop k-1 elements and store them in temp
            for (int j = 0; j < k - 1; ++j) {
                temp.push_back(distances.top());
                distances.pop();
            }

            // Output the kth nearest hostel distance
            cout << distances.top() << endl;

            // Restore the popped elements to the priority queue
            for (int j = 0; j < k - 1; ++j) {
                distances.push(temp[j]);
            }
        }
    }

    return 0;
}
