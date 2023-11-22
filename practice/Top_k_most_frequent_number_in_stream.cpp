#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

struct Element {
    int number;
    int frequency;

    Element(int num, int freq) : number(num), frequency(freq) {}

    bool operator>(const Element& other) const {
        if (frequency == other.frequency) {
            return number < other.number;
        }
        return frequency < other.frequency;
    }
};

void topKFrequent(const vector<int>& nums, int k) {
    unordered_map<int, int> frequencyMap;
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;

    for (int num : nums) {
        frequencyMap[num]++;
        minHeap.push(Element(num, frequencyMap[num]));

        vector<Element> elements;
        while (!minHeap.empty()) {
            elements.push_back(minHeap.top());
            minHeap.pop();
        }

        reverse(elements.begin(), elements.end());

        for (const Element& e : elements) {
            for (int i = 0; i < e.frequency; ++i) {
                cout << e.number;
                if (--k == 0) {
                    return;
                }
            }
        }

        for (const Element& e : elements) {
            minHeap.push(e);
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        topKFrequent(nums, k);
        cout << endl;
    }

    return 0;
}
