#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    vector<int> list1;
    vector<int> list2;

    ifstream file("day1inp.txt");

    int curr;
    int c = 0;
    while (file >> curr) {
        if (c%2 == 0) {
            list1.push_back(curr);
        } else {
            list2.push_back(curr);
        }
        c++;
    }
    file.close();

    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    int dif = 0;
    for (int i = 0; i < 1000; i++) {
        dif += abs(list1[i] - list2[i]);
    }

    cout << dif; // 3246517
}