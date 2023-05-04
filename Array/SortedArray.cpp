#include <iostream>
#include <string.h>
using namespace std;

void Sorting(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        for(int j=0; j<n-1-i; j++){
        if (arr[j] > arr[j+1])
        {
            swap(arr[j], arr[j+1]);
        }
    }
    }
    for(int i=0; i<n; i++){

    cout<<arr[i]<<" ";
    }
   
    //return arr[n];
}
int main()
{
    int n, arr[n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Sorting(arr, n);
}