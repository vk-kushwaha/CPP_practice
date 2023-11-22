/*

Given a number N. Find the minimum number of operations required to reach N starting from 0. You have 2 operations available:

Double the number
Add one to the number
Example 1:

Input:
N = 8
Output: 4
Explanation: 
0 + 1 = 1 --> 1 + 1 = 2 --> 2 * 2 = 4 --> 4 * 2 = 8.
Example 2:

Input: 
N = 7
Output: 5
Explanation: 
0 + 1 = 1 --> 1 + 1 = 2 --> 1 + 2 = 3 --> 3 * 2 = 6 --> 6 + 1 = 7.
Your Task:
You don't need to read input or print anything. Your task is to complete the function minOperation() which accepts an integer N and return number of minimum operations required to reach N from 0.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperation(int N) {
        int result = 0;

        while (N > 0) {
            if (N % 2 == 0) {
                N /= 2;
            } else {
                N -= 1;
            }
            result++;
        }

        return result;
    }
};

int main() {
    int N = 8;
    Solution solver;
    int result = solver.minOperation(N);

    cout << "Minimum operations to reach " << N << " is: " << result << std::endl;
    return 0;
}
