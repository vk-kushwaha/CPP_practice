/*
Given a number N and a bit number K, check if Kth index bit of N is set or not. A bit is called set if it is 1. Position of set bit '1' should be indexed starting with 0 from LSB side in binary representation of the number.
Note: Index is starting from 0. You just need to return true or false, driver code will take care of printing "Yes" and "No".

Example 1:

Input: 
N = 4
K = 0
Output: 
No
Explanation: 
Binary representation of 4 is 100, in which 0th index bit from LSB is not set. So, return false.
Example 2:

Input: 
N = 4
K = 2
Output: 
Yes
Explanation: 
Binary representation of 4 is 100, in which 2nd index bit from LSB is set. So, return true.
*/

#include <iostream>
using namespace std;

bool isKthBitSet(int N, int K) {
    // Left shift 1 by K positions to create a mask with the Kth bit set
    int mask = 1 << K;

    // Use bitwise AND to check if the Kth bit is set
    if ((N & mask) != 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int N, K;
    cin >> N;
    cin >> K;

    if (isKthBitSet(N, K)) {
        cout << "Yes" << std::endl;
    } else {
        cout << "No" << std::endl;
    }

    return 0;
}
