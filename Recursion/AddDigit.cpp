// Given a non-negative integer num, 
//repeatedly add all its digits until the result has only one digit.

#include <iostream>
using namespace std;

int addDigits(int num)
{

    if (num < 10)
    {
        return num;
    }
    int sum = 0;
    while (num != 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return addDigits(sum);
}

int main()
{
    int num;
    cin >> num;

    int result = addDigits(num);
    cout << result << endl;

    return 0;
}
