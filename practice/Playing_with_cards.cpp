#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 100005;
const int MAX_Q = 100005;

vector<int> primes; // vector to store prime numbers

void sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
        if (isPrime[p])
            primes.push_back(p);
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a0(n);
    for (int i = 0; i < n; i++)
        cin >> a0[i];

    sieve(50); // Assuming the maximum prime required is 50

    queue<int> piles[MAX_Q + 1];

    for (int i = 1; i <= q; i++) {
        for (int j = 0; j < n; j++) {
            int card = a0[j];
            if (card % primes[i - 1] == 0)
                piles[i].push(card);
            else
                piles[0].push(card);
        }
    }

    for (int i = 1; i <= q; i++) {
        while (!piles[i].empty()) {
            cout << piles[i].front() << endl;
            piles[i].pop();
        }
    }

    while (!piles[0].empty()) {
        cout << piles[0].front() << endl;
        piles[0].pop();
    }

    return 0;
}
