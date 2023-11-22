#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

struct Element {
    int value;
    int frequency;

    Element(int val, int freq) : value(val), frequency(freq) {}

    bool operator>(const Element& other) const {
        return frequency > other.frequency;
    }
};

vector<int> topKFrequentElements(const vector<int>& nums, int k) {
    unordered_map<int, int> frequencyMap;

    for (int num : nums) {
        frequencyMap[num]++;
    }

    priority_queue<Element, vector<Element>, greater<Element>> minHeap;

    for (const auto& entry : frequencyMap) {
        minHeap.push(Element(entry.first, entry.second));

        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    vector<int> result;
    result.reserve(k);  // Reserve space to avoid reallocation

    while (!minHeap.empty()) {
        result.push_back(minHeap.top().value);
        minHeap.pop();
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    int N, k;
    cin >> N >> k;

    vector<int> nums(N);

    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    vector<int> result = topKFrequentElements(nums, k);

    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
