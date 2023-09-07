#include <iostream>
#include <vector>
using namespace std;

void genNumber(vector<int>& result, int n, int k, int current, int len) {
    if (len == n) {
        result.push_back(current);
        return;
    }

    int lastDigit = current % 10;

    if (lastDigit + k <= 9) {
        genNumber(result, n, k, current * 10 + (lastDigit + k), len + 1);
    }

    if (lastDigit - k >= 0 && k != 0) {
        genNumber(result, n, k, current * 10 + (lastDigit - k), len + 1);
    }
}

vector<int> getNumber(int n, int k) {
    vector<int> result;
    for (int i = 1; i <= 9; ++i) {
        genNumber(result, n, k, i, 1);
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> numbers = getNumber(n, k);

    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
