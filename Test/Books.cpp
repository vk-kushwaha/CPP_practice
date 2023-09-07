#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> books(N);
    for (int i = 0; i < N; ++i) {
        cin >> books[i];
    }

    int left = 0, right = 0;
    int Sum = 0;
    int ReadBook = 0;

    while (right < N) 
    {
        Sum += books[right];
  while (Sum > T) {
            Sum -= books[left];
            left++;
        }

        ReadBook = max(ReadBook, right - left + 1);
        right++;
    }

    cout << ReadBook << endl;

    return 0;
}
