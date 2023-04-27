#include<iostream>
using namespace std;
int main(){
    int n;

    cout<< "Enter any number do you want table for ";
    cin>>n;
    cout<<"\n Showing table of "<<n<<endl<<endl;
    for(int i=1; i<=10; i++){
        cout<<n <<" * "<< i<< " = "<<n*i<<endl;
    }
}