#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<int> stairs(n);
    for (int i = 0; i < n; ++i) {
        cin >> stairs[i];
    }

    vector<int> alpha_scores(n, 0);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (stairs[i] > stairs[j]) {
                alpha_scores[i] = (alpha_scores[i] + stairs[j]) % MOD;
            }
        }
    }

    int total_alpha_score = 0;
    for (int i = 0; i < n; ++i) {
        total_alpha_score = (total_alpha_score + alpha_scores[i]) % MOD;
    }

    cout << total_alpha_score << endl;

    return 0;
}