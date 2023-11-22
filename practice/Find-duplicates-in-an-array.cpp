/*Given an array a of size N which contains elements from 0 to N-1, 
you need to find all the elements occurring more than once in the given
 array. Return the answer in ascending order. If no such element is found,
  return list containing [-1]. 

Note: The extra space is only for the array to be returned.
 Try and perform all operations within the provided array.


 Input:
N = 4
a[] = {0,3,1,2}
Output: 
-1
Explanation: 
There is no repeating element in the array. Therefore output is -1.
Example 2:

Input:
N = 5
a[] = {2,3,1,2,3}
Output: 
2 3 
Explanation: 
2 and 3 occur more than once in the given array.

 */ 
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> duplicates(int a[], int N) {
        vector<int> result;
        set<int> seen;

        for (int i = 0; i < N; i++) {
            if (seen.find(a[i]) != seen.end()) {
                result.push_back(a[i]);
            }
            seen.insert(a[i]);
        }

        if (result.empty()) {
            result.push_back(-1);
        } else {
            sort(result.begin(), result.end());
        }

        return result;
    }
};

int main() {
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    Solution obj;
    vector<int> ans = obj.duplicates(a, N);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
