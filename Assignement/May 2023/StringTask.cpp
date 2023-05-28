
//incomplet hai abhi.


#include<iostream>
using namespace std;
int main(){

    string str,ans;
    cin>>str;

    for(int i=0; i<=str.length(); i++){
        if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' || str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
    
            str[i-1]=str['.'];
    //     ans[i+1]+=str[i];
    // 
    }
    
    for(int i=0; i<=str.length(); i++){
    cout<<ans[i];
    }
}