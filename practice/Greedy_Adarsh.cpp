#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int maxConsecutiveBooks(vector<int>& books) {
    int maxCount = 0;

    unordered_set<int> uniqueIds;

    for (int id : books) {
        uniqueIds.insert(id);
    }

    for (int id : books) {
        if (uniqueIds.find(id) != uniqueIds.end()) {
            int count = 1;
            int prevId = id - 1;

            while (uniqueIds.find(prevId) != uniqueIds.end()) {
                uniqueIds.erase(prevId);
                count++;
                prevId--;
            }

            int nextId = id + 1;
            while (uniqueIds.find(nextId) != uniqueIds.end()) {
                uniqueIds.erase(nextId);
                count++;
                nextId++;
            }

            maxCount = max(maxCount, count);
        }
    }

    return maxCount;
}

int main() {
    int N;
    cin >> N;

    vector<int> books(N);
    for (int i = 0; i < N; ++i) {
        cin >> books[i];
    }

    int result = maxConsecutiveBooks(books);
    cout << result << endl;

    return 0;
}
