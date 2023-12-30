
#include<bits/stdc++.h>
using namespace std;

 const double PI = 3.14159265358979323846;

double calculateArea(int ch, const vector<int>& a) {
    switch (ch) {
        case 1: {
            double area = M_PI * a[0] * a[0];
           double areac = round(area*100000)/100000;
            return areac;
        }
        case 2: {
            double area = static_cast<double>(a[0] * a[1]);
            return area;
        }
        default:
            return 0.0; 
    }
}

int main() {
    int ch;
    vector<int> a(2);

    cin >> ch;

    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
    }

    double result = calculateArea(ch, a);

    cout << result;

    return 0;
}
