#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        unordered_set<int> arrSet;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            arrSet.insert(num);
        }
        
        int q;
        cin >> q;
        
        while (q--) {
            int query;
            cin >> query;
            
            if (arrSet.find(query) != arrSet.end()) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
