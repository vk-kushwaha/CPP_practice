#include<iostream>
using namespace std;

int IncNo(int n){
    if(n==0){
        return 1;
    }
    
    IncNo(n-1);
    cout<<n<<endl;
    return n;
}
int main(){
    int n;
    cin>>n;

    IncNo(n);

}