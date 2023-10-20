#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution{
public:
    bool ispar(string x){
        stack<char> s;

        for(char c: x){
            if (c=='(' || c=='{' || c=='['){
                s.push(c);
            }
            else{
                if(s.empty()){
                    return false;
                }

                char top= s.top();
                if ((c==')' && top =='(')||
                    (c=='}' && top == '{') ||
                    (c== ']' && top == '['))
                {
                    s.pop();

                }
                else{
                    return false;
                }
            }
            
        }
        return s.empty();
    }
};

int main(){

    int t;
    cin >>t;

    while(t--){
        string exp;
        cin>>exp;

        Solution sol;

        if(sol.ispar(exp)){

            cout<< " Balanced"<<endl;
        }else{
            cout<< "Not Balanced" <<endl;
        }
    }

    return 0;
}