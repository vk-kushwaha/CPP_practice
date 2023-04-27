#include<iostream>
using namespace std;

float AreaOfCicle(int Rad){

float Area=3.14*Rad*Rad;
return Area;
}

float Circum(int Rad){

float Circum=2*3.14*Rad;
return Circum;

}

int main(){

cout<<AreaOfCicle(5);
cout<<endl;
cout<<Circum(5);
}