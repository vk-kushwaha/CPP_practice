#include<iostream>
using namespace std;
int Factroial(int n){
    int Fact=1;
    for(int i=n; i>=1; i--){
        Fact= Fact*i;
    }
    return Fact;
}

int main(){
    int n;
    cout <<"Enter any number to get factorial \n";
    cin>>n;


    cout<<"Factorail Of "<<n<<" = "<<Factroial(n);
    return 0;

}