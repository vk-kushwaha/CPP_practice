/*

Take as input str, a string. We are concerned with all possible permutations of characters in str. E.g. “abc” can produce following words “abc”, “acb”, “bac”, “bca”, “cab”, “cba”

a. Write a recursive function which returns the count of different permutations for a given string. Print the value returned.

b. Write a recursive function which prints all possible permutations for a given string in the lexicographical order (void is the return type for function).

Input Format
Enter the String

Constraints
None

Output Format
Display the total number of permutations, display the arraylist containing all the permutations, print all the permutations in a space separated manner

Sample Input
abc
Sample Output
6
abc acb bac bca cab cba 

*/



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Part A: Recursive function to count permutations
int countPermutations(string str) {
    if (str.empty()) {
        return 1;
    }

    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        string remaining = str.substr(0, i) + str.substr(i + 1);
        count += countPermutations(remaining);
    }

    return count;
}

// Part B: Recursive function to print permutations
void printPermutations(string str, string prefix) {
    if (str.empty()) {
        cout << prefix << " ";
        return;
    }

    for (int i = 0; i < str.length(); i++) {
        string remaining = str.substr(0, i) + str.substr(i + 1);
        printPermutations(remaining, prefix + str[i]);
    }
}

int main() {
    string input;
    cin >> input;

    // Part A: Count and display the total number of permutations
    int totalPermutations = countPermutations(input);
    cout << totalPermutations << endl;

    // Part B: Print all permutations in lexicographical order
    sort(input.begin(), input.end());
    printPermutations(input, "");

    return 0;
}
