#include <iostream>
using namespace std;

void DecNoRecursive(int n)
{

    if (n == 0)
        return;

    cout << n << " ";

    DecNoRecursive(n - 1);
}

int main()
{

    int n;
    cout << "Enter any number to printer reverse from\n";
    cin >> n;

    DecNoRecursive(n);

    return 0;
}