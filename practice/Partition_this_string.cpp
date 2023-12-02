#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> partitionLabels(string s) {
    unordered_map<char, int> lastOccurrence;

    // Store the last occurrence index of each character
    for (int i = 0; i < s.length(); i++) {
        lastOccurrence[s[i]] = i;
    }

    vector<int> result;
    int start = 0, end = 0;

    for (int i = 0; i < s.length(); i++) {
        end = max(end, lastOccurrence[s[i]]);

        // If the current index is equal to the end index, we found a partition
        if (i == end) {
            result.push_back(end - start + 1);
            start = i + 1;
        }
    }

    return result;
}

int main() {
    string s;
    cin >> s;

    vector<int> partitions = partitionLabels(s);

    for (int size : partitions) {
        cout << size << " ";
    }

    return 0;
}
