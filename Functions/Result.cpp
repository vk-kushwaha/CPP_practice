#include<iostream>
using namespace std;

int Grades(int marks){
    
    if(marks <= 40)
    cout<<"Fail\n";
    else if(marks>=41 && marks<=50)
    cout<<"DD Grade\n";
    else if(marks>=51 && marks<=60)
    cout<<"CD Grade\n";
    else if(marks>=61 && marks<=70)
    cout<<"BC Grade\n";
    else if(marks>=71 && marks<=80)
    cout<<"BB Grade\n";
    else if(marks>=81 && marks<=90)
    cout<<"AB Grade\n";
    else if(marks>=91 && marks<=100)
    cout<<"AA Grade\n";
    
    return 0;
    
}

int main(){
    int marks;
    cout<<"Enter your marks\n";
    cin>>marks;

    Grades(marks);

    return 0;
}
