/*Take an input str, a string. A “twin” is defined as
two instances of a char separated by a char. E.g. "AxA"
the A's make a “twin”. “twins” can overlap,
 so "AxAxA" contains 3 “twins” - 2 for A and 1 for x.
 Write a function which recursively counts number of “twins”
 in a string. Print the value returned.*/

#include <iostream>
using namespace std;

int countTwins(string str, int index = 0)
{
    if (str.length() < 3)
        return 0;

    int count = 0;
    if (index < str.length() - 2)
    {
        if (str[index] == str[index + 2])
            count = 1;
        count += countTwins(str, index + 1);
    }

    return count;
}

int main()
{
    string input;
    cin >> input;

    int twinCount = countTwins(input);
    cout << twinCount << endl;

    return 0;
}
