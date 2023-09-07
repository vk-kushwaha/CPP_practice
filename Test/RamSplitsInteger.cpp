#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int  maxProd = 0;

    for (int k = 2; k <= n; ++k) {
        int quotient = n / k;
        int remainder = n % k;

      
        int product = 1;
        for (int i = 0; i < k - remainder; i++) {
            product =product*  quotient;
        }
        for (int i = 0; i < remainder; i++) {
            product =product* (quotient + 1);
        }

       
        maxProd = max(maxProd, product);
    }

    cout << maxProd << endl;

    return 0;
}
