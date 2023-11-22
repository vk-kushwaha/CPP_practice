#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void simpleSieve(int limit, vector<int> &primes) {
    vector<bool> isPrime(limit + 1, true);
    for (int p = 2; p * p <= limit; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }
    for (int p = 2; p <= limit; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }
}

void segmentedSieve(int m, int n) {
    int limit = floor(sqrt(n)) + 1;
    vector<int> primes;
    simpleSieve(limit, primes);
    
    int range = n - m + 1;
    vector<bool> isPrime(range, true);
    for (int i = 0; i < primes.size(); ++i) {
        int start = max(primes[i] * primes[i], (m + primes[i] - 1) / primes[i] * primes[i]);
        for (int j = start; j <= n; j += primes[i]) {
            isPrime[j - m] = false;
        }
    }

    for (int i = max(m, 2); i <= n; ++i) {
        if (isPrime[i - m]) {
            cout << i << endl;
        }
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int m, n;
        cin >> m >> n;
        segmentedSieve(m, n);
    }

    return 0;
}