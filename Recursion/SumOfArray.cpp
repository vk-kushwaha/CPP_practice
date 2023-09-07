#include <iostream>
using namespace std;


// Bottum up approach
int SumOfArray(int *arr, int n)
{

    if (n == 0)
        return 0;

    return arr[n - 1] + SumOfArray(arr, n - 1);
}



// Top Down approach.
int SumOfArray2(int *arr, int idx, int n){

    if(idx==n)
    return 0;

    int ans= arr[idx]+ SumOfArray2(arr,idx+1,n);
    return ans;
}

// main function to run this code.
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << endl<< SumOfArray(arr, n);

    cout<<endl<<SumOfArray2(arr,0,n);

    return 0;
}