#include <iostream>
#include <vector>

using namespace std;

void printSpiral(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // Print top row
        for (int i = left; i <= right; i++) {
            cout << matrix[top][i];
            if (i != right || top != bottom) {
                cout << ", ";
            }
        }
        top++;

        // Print right column
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right];
            if (i != bottom || left != right) {
                cout << ", ";
            }
        }
        right--;

        // Print bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                cout << matrix[bottom][i];
                if (i != left || top != bottom) {
                    cout << ", ";
                }
            }
            bottom--;
        }

        // Print left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << matrix[i][left];
                if (i != top || left != right) {
                    cout << ", ";
                }
            }
            left++;
        }
    }

    cout << ", END" << endl;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    printSpiral(matrix);

    return 0;
}
