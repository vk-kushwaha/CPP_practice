#include<iostream>
#include<string.h>
using namespace std;

void Transpose(int arr[][3], int n){

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
}

void PrintMatrics(int arr[][3], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){

    int arr[3][3];
    int n=3;

    cout<<"\nENter values for matrics 3x3\n";

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
           cin>>arr[i][j];
        }
    }

    Transpose(arr,n);

    PrintMatrics(arr,n);



}
