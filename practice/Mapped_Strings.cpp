#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

// Function to convert a number to its corresponding character
char getChar(int num) {
    return 'A' + num - 1;
}

// Function to generate all possible strings for a given number
void generateStrings(int num, string current, vector<string>& result) {
    if (num == 0) {
        result.push_back(current);
        return;
    }

    // Take one digit
    int digit = num % 10;
    if (digit != 0) {
        generateStrings(num / 10, getChar(digit) + current, result);
    }

    // Take two digits if possible
    if (num >= 10 && num % 100 <= 26 && num % 100 >= 10) {
        generateStrings(num / 100, getChar(num % 100) + current, result);
    }
}

int main() {
    int num;
    cin >> num;

    vector<string> result;
    generateStrings(num, "", result);

    // Print the result in sorted order
    sort(result.begin(), result.end());
    for (const string& s : result) {
        cout << s << endl;
    }

    return 0;
}
