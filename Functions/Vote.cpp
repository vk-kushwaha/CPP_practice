#include<iostream>
using namespace std;

void EligibleForVote(int age){
    if(age>=18){
    cout<<"\nEligible for Vote\n";        
    }
    else 
    cout<<"\nNot Eligible For Vote\n";
}

int main(){
int age;
cout<<"Enter your age to check eligibilty\n";
cin>>age;

EligibleForVote(age);
}