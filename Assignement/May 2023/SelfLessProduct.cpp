#include<iostream>
using namespace std;
 
 int main(){
int n, arr[100], ans[100];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for (int  i = 0; i < n; i++)
     {ans[i]=1;
      
        for(int j = 0; j < n; j++)
        {
          if(i!=j)
          ans[i]=ans[i]*arr[j];
        }
        
    }
    for(int i=0; i<n; i++)
  {

   cout<<ans[i]<<" ";
    
 }
 }
