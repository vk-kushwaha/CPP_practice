#include <iostream>
using namespace std;

int main() {
    int n;
    //cout << "Enter the value of N (odd number): ";
    cin >> n;
    if (n % 2 == 0) {
        cout << "N must be an odd number";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (i <= (n+1)/2) {
            for (int j = 0; j <= n/2-i; j++) {
                cout << "       ";
            }
            for (int j = 1; j <= 2*i-1; j++) {
                cout << "*      ";
            }
        } else {
            for (int j = 1; j <= (i-n/2)-1; j++) {
                cout << "       ";
            }
            for (int j = 1; j <= 2*(n-i)+1; j++) {
                cout << "*      ";
            }
        }
        cout << endl;
    }
    return 0;
}