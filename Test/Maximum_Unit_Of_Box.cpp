#include <iostream>
#include <vector>
using namespace std;

int maxUnits(vector<vector<int>>& boxTypes, int tSize) {
    vector<int> bucket(1001, 0);

    for (const vector<int>& boxType : boxTypes) {
        int numOfBoxes = boxType[0];
        int unitsPerBox = boxType[1];
        bucket[unitsPerBox] += numOfBoxes;
    }

    int totalUnits = 0;
    int boxCount = 0;
    for (int i = 1000; i >= 0; i--) {
        if (bucket[i] > 0) {
            int boxToPut = min(bucket[i], tSize - boxCount);
            totalUnits += boxToPut * i;
            boxCount += boxToPut;

            if (boxCount >= tSize) {
                break;
            }
        }
    }

    return totalUnits;
}

int main() {
    int n, tSize;
    cin >> n >> tSize;

    vector<vector<int>> boxTypes(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> boxTypes[i][0] >> boxTypes[i][1];
    }

    int result = maxUnits(boxTypes, tSize);
    cout << result << endl;

    return 0;
}
