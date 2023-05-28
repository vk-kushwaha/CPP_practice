#include <iostream>
using namespace std;

bool IsSorted(int arr[], int pos, int n)
{

    if (arr[0] > arr[1])
        swap(arr[0], arr[1]);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }

    return true;
}

int main()
{
    int n, arr[100], pos;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    IsSorted(arr, 0, n);
    if (IsSorted)
        cout << "yes";
    else
        cout << "No";

    for (int i = 0; i < n; i++)
    {
        cout << endl
             << arr[i] << " ";
    }
}