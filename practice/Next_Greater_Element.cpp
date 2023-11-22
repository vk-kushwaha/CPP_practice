#include <iostream>
#include <stack>

using namespace std;

void nextGreater(int arr[], int n) {
    stack<int> st;
    int nextGreater[n];

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            st.pop();
        }
        nextGreater[i] = (st.empty() ? -1 : arr[st.top()]);
        st.push(i);
    }

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << "," << nextGreater[i] << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        nextGreater(arr, n);
    }

    return 0;
}
