/*Design a traffic light in which you take the color of light C as input. If the color is "red" then print "Please turn off your engine". If the color is "yellow" print "Hey, please ready to move". If the color is "green" then print "You are clear to move ahead".

Input Format
The first line contains a integer T, number of test cases.
First line of each test case contains a string C.

Constraints
0<T<1000

Output Format
Display a single line output for each test case containing the result.

Sample Input
3
red
green
yellow*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;

    while (T--) {
        string color;
        cout << "Enter the color of the traffic light (red/yellow/green): ";
        cin >> color;

        if (color == "red") {
            cout << "Please turn off your engine" << endl;
        } else if (color == "yellow") {
            cout << "Hey, please ready to move" << endl;
        } else if (color == "green") {
            cout << "You are clear to move ahead" << endl;
        } else {
            cout << "Invalid input. Please enter either red, yellow, or green." << endl;
        }
    }

    return 0;
}
