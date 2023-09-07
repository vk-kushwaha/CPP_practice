#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> target = {4, 8, 15, 16, 23, 42};
    stack<int> s;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 4) {
            s.push(0);
        } else {
            while (!s.empty() && arr[i] != target[s.top() + 1]) {
                count++;
                s.pop();
            }

            if (!s.empty()) {
                s.top()++;
                if (s.top() == 5) {
                    s.pop();
                }
            } else {
                count++;
            }
        }
    }
    count += s.size() * 6;

    cout << count << endl;

    return 0;
}
