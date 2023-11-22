/*
We are given an array containg n numbers. All the numbers are present twice except for two numbers which are present only once. Find the unique numbers in linear time without using any extra space. ( Hint - Use Bitwise )


Input format

First line contains the number n. Second line contains n space separated number.


Output format

Output a single line containing the unique numbers separated by space


Example 1

Input

4
3 1 2 1


Output

2 3


Explanation

Smaller number comes before larger number
*/ 


#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    int xor_result = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        xor_result ^= arr[i];
    }

    // Find the rightmost set bit
    int rightmost_set_bit = 1;
    while ((xor_result & rightmost_set_bit) == 0) {
        rightmost_set_bit <<= 1;
    }

    int unique1 = 0, unique2 = 0;

    // Divide the elements into two groups based on the rightmost set bit
    for (int i = 0; i < n; i++) {
        if (arr[i] & rightmost_set_bit) {
            unique1 ^= arr[i];
        } else {
            unique2 ^= arr[i];
        }
    }

    if (unique1 < unique2) {
        cout << unique1 << " " << unique2 << endl;
    } else {
        cout << unique2 << " " << unique1 << endl;
    }

    return 0;
}
