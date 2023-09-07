#include <iostream>
using namespace std;

int Factorial(int n)
{
    if (n == 0 || n==1)
    {
        return 1;
    }
    return n * Factorial(n - 1);
    
}
int main()
{
    int n;
    cout << "Enter number to get factorial \n";
    cin >> n;

    int ans = Factorial(n);
    cout << ans << endl;

    return 0;
}