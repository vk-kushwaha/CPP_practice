#include<iostream>
#include<stack>
using namespace std;

void NextgreaterNumberCircular(int *arr, int *ans, int n) {
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--) {
        int index = i % n;

        while (!st.empty() && arr[index] >= arr[st.top()]) {
            st.pop();
        }

        if (i < n) {
            ans[index] = st.empty() ? -1 : arr[st.top()];
        }

        st.push(index);
    }
}

int main() {	
    int n;
    cin >> n;
    int arr[n];
    int ans[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    NextgreaterNumberCircular(arr, ans, n);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
