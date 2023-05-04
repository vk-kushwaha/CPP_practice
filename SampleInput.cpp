#include <iostream>
using namespace std;
int main()
{

    int arr[10];
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Length of Array = " << n << endl;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        sum = sum +( arr[i]);
        if(sum > 0)
            cout << "Non Negative values = " << arr[i] << endl;
        else
        break;
    }
}
