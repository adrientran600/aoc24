#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int safe_count = 1000;

    ifstream file("day2inp.txt");

    string line;
    while (getline (file, line)) {
        stringstream ss(line);
        vector<int> report;
        int curr;
        // cout << line
        while (ss >> curr) {
            report.push_back(curr);
        }

        bool decreasing = false;
        for (int i = 0; i < report.size() - 1; i++) {
            int dif = report[i] - report[i + 1];
            if (i == 0 && dif > 0) {
                decreasing = true;
            }
            if (dif == 0 || dif > 3 || dif < -3 || (decreasing && dif < 0) || (!decreasing && dif > 0)) {
                safe_count--;
                break;
            }
        }
    }
    file.close();

    cout << safe_count << endl;
}