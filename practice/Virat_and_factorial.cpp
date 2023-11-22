#include <iostream>
using namespace std;

const int MAX_DIGITS = 200; // Adjust this value as needed

void calculateFactorial(int N, int result[]) {
    result[0] = 1;
    int resultSize = 1;

    for (int i = 2; i <= N; i++) {
        int carry = 0;
        for (int j = 0; j < resultSize; j++) {
            int product = result[j] * i + carry;
            result[j] = product % 10;
            carry = product / 10;
        }

        while (carry > 0) {
            result[resultSize] = carry % 10;
            carry /= 10;
            resultSize++;
        }
    }

    for (int i = resultSize - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    int result[MAX_DIGITS] = {0};

    if (N == 0) {
        cout << "1" << endl;
    } else {
        calculateFactorial(N, result);
    }

    return 0;
}
