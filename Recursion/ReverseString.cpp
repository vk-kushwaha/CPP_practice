#include <iostream>
using namespace std;

void Reverse(string &str, int start, int end)
{

    if (start >= end)
        return;

    swap(str[start], str[end]);

    Reverse(str, start + 1, end - 1);
}
int main()
{

    string str;
    cin >> str;

    Reverse(str, 0, str.length() - 1);
    cout << str;
    return 0;
}