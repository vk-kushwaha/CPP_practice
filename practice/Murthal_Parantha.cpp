#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canCookAllParanthas(vector<int>& ranks, int L, int P, int mid) {
    int count = 0;
    for (int i = 0; i < L; i++) {
        int time = ranks[i];
        int j = 2;
        while (time <= mid) {
            count++;
            time += ranks[i] * j;
            j++;
        }
    }
    return count >= P;
}

int minimumTimeToCookParanthas(int P, int L, vector<int>& ranks) {
    int low = 0;
    int high = P * (P + 1) / 2 * *max_element(ranks.begin(), ranks.end());
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canCookAllParanthas(ranks, L, P, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int P;
    cin >> P;

    int L;
    cin >> L;

    vector<int> ranks(L);
    for (int i = 0; i < L; i++) {
        cin >> ranks[i];
    }

    int result = minimumTimeToCookParanthas(P, L, ranks);
    cout << result << endl;

    return 0;
}
