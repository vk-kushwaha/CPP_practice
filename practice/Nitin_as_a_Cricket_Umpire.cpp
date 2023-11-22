#include <iostream>
#include <cmath>

using namespace std;

int countNumbersWithUniqueDigits(int n) {
    if (n == 0) {
        return 1;
    }

    int result = 10; 

    for (int i = 2; i <= min(n, 10); ++i) {
        int uniqueDigits = 9;
        for (int j = 9; j >= 9 - i + 2; --j) {
            uniqueDigits *= j;
        }
        result += uniqueDigits;
    }

    return result;
}

int main() {
    int N;
    cin >> N;

    int result = countNumbersWithUniqueDigits(N);
    cout << result << endl;

    return 0;
}
