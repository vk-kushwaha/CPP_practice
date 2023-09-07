#include <iostream>
using namespace std;

int max(int arr[], int start, int end)
{
    if (start == end)
        return arr[start];

    int mid = (start + end) / 2;
    int max1 = max(arr, start, mid);
    int max2 = max(arr, mid + 1, end);

    if (max1 < max2)
        return max2;
    else
        return max1;
}

int min(int arr[], int start, int end)
{

    if (start == end)
        return arr[start];

    int mid = (start + end) / 2;
    int min1 = min(arr, start, mid);
    int min2 = min(arr, mid + 1, end);

    if (min1 < min2)
        return min1;
    else
        return min2;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // int size= sizeof(arr)/sizeof(arr[0]);

    int Maximum = max(arr, 0, n-1);
    int Minimum = min(arr, 0, n-1 );

    cout <<"max Number"<< Maximum << endl;
    cout << "Min Number"<<Minimum << endl;

    return 0;
}