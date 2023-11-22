/*Take as input N, the size of array. Take N more inputs and store that in an array. 
Take as input a number M. Write a function which returns the index on which M is found 
in the array, in case M is not found -1 is returned. Print the value returned.You can 
assume that the array is sorted, but you’ve to optimize the finding process.
 For an array of size 1024, you can make 10 comparisons at maximum.


1.It reads a number N.

2.Take Another N numbers as input in Ascending Order and store them in an Array.

3.Take Another number M as input and find that number in Array.

4.If the number M is found, index of M is returned else -1 is returned.Print the number returned.


Example 1

Input

5
3
5
6
9
78
6


Output

2


Explanation

Array = {3, 5, 6, 9, 78}, target number = 6 . Index of number 6 in the given array = 2.
Write Binary search to find the number in given array as discuss in the class.*/ 


#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  // Element found, return its index
        }

        if (arr[mid] < target) {
            left = mid + 1; // Search the right half
        } else {
            right = mid - 1; // Search the left half
        }
    }

    return -1; // Element not found
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int M;
    cin >> M;

    int result = binarySearch(arr, M);

    cout << result << endl;

    return 0;
}
