#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int main() {
    map<int, int> list1;
    map<int, int> list2;

    ifstream file("day1inp.txt");

    int curr;
    int c = 0;
    while (file >> curr) {
        if (c%2 == 0) {
            list1[curr]++;
        } else {
            list2[curr]++;
        }
        c++;
    }

    int sim_score = 0;
    for (auto elem : list1) {
        sim_score += elem.first * elem.second * list2[elem.first];
    }

    cout << sim_score; // 3246517
}