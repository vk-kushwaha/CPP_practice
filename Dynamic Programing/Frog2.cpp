#include<iostream>
 #include<bits/stdc++.h>
#include<climits>
using namespace std;
int k;
int Solve(int * height,int x, int n){
    if (x==n){
        return 0;
    }

    int OP=INT_MAX;
    for (int j = 1; j <=k;  j++)
    {
        if(x+j<=n){
        int jump=abs(height[x]-height[j+x]);
        int rest=Solve(height, x+j,n);
        OP=min(OP,rest+jump);
        }
    }
    return OP;    
}

int Solve2(int * height, int x){
    if(x==0)
    return 0;

    int OP= INT_MAX;

    for(int i=1; i<=k; i++){
        if(x-i>=0){
        int jump= abs(height[x]-height[x-i]);
        int rest= Solve2(height, x-i);

        OP= min(OP,rest+jump);
        
        }
    }
    return OP;
}
int main(){
 int n;
   
    cin>>n>>k;
     int height[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>height[i];
    }
    

    cout<<Solve(height,0,n-1)<<endl;

    cout<<Solve2(height, n-1)<<endl;

 return 0;
}