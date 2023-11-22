#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool customCompare(string a, string b) {
    if (a.find(b) == 0) {
        return a.length() > b.length();
    }
    if (b.find(a) == 0) {
        return a.length() < b.length();
    }
    return a < b;
}

int main() {
    int N;
    cin >> N;

    vector<string> strings(N);

    for (int i = 0; i < N; i++) {
        cin >> strings[i];
    }

    sort(strings.begin(), strings.end(), customCompare);


    for (int i = 0; i < N; i++) {
        cout << strings[i] << endl;
    }

    return 0;
}
