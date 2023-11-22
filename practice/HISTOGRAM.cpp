#include <iostream>
#include <stack>
#include <vector>

using namespace std;

long long largestRectangleArea(vector<long long>& heights) {
    stack<long long> s;
    long long maxArea = 0;

    for (long long i = 0; i < heights.size();) {
        if (s.empty() || heights[i] >= heights[s.top()]) {
            s.push(i);
            i++;
        } else {
            long long topIndex = s.top();
            s.pop();

            long long width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, heights[topIndex] * width);
        }
    }

    while (!s.empty()) {
        long long topIndex = s.top();
        s.pop();

        long long width = s.empty() ? heights.size() : heights.size() - s.top() - 1;
        maxArea = max(maxArea, heights[topIndex] * width);
    }

    return maxArea;
}

int main() {
    long long N;
    cin >> N;

    vector<long long> heights(N);
    for (long long i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    long long result = largestRectangleArea(heights);
    cout << result << endl;

    return 0;
}
