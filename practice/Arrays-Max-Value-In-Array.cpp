/*Take an input N, the size of array. Take N more inputs and store that in an array. Write a function which returns the maximum value in the array. Print the value returned.


1.It reads a number N.


2.Take Another N numbers as input and store them in an Array.


3.calculate the max value in the array and return that value.


Input format

First line contains integer n as size of array. Next n lines contains a single integer as element of array.


Output format

Print the required output.


Example 1

Input

4
2
8
6
4


Output

8


Explanation

Arrays= {2, 8, 6, 4} => Max value = 8 .*/ 


#include <iostream>
#include <vector>

using namespace std;

int findMax(vector<int>& arr) {
    int maxVal = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    return maxVal;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxVal = findMax(arr);

    cout << maxVal << endl;

    return 0;
}
