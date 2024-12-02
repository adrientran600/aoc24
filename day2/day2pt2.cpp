#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

bool tryAll(vector<int> &report) {
    int unsafe_count = 0;
    for (int i = 0; i < report.size(); i++) {
        vector<int> temp_report = report;
        temp_report.erase(temp_report.begin() + i);

        bool decreasing = false;
        for (int i = 0; i < temp_report.size() - 1; i++) {
            int dif = temp_report[i] - temp_report[i + 1];
            if (i == 0 && dif > 0) {
                decreasing = true;
            }
            if (dif == 0 || dif > 3 || dif < -3 || (decreasing && dif < 0) || (!decreasing && dif > 0)) {
                unsafe_count++;
                break;
            }
        }
    }
    return (report.size() > unsafe_count);
}

int main() {
    int safe_count = 0;

    ifstream file("day2inp.txt");

    string line;
    while (getline (file, line)) {
        stringstream ss(line);
        vector<int> report;
        int curr;
        while (ss >> curr) {
            report.push_back(curr);
        }

        bool decreasing = false;
        bool safe = true;
        for (int i = 0; i < report.size() - 1; i++) {
            int dif = report[i] - report[i + 1];
            if (i == 0 && dif > 0) {
                decreasing = true;
            }
            if (dif == 0 || dif > 3 || dif < -3 || (decreasing && dif < 0) || (!decreasing && dif > 0)) {
                safe = tryAll(report); 
            }
        }
        if (safe) {
            safe_count++;
            // cout << line << endl;
        }
    }
    file.close();

    cout << safe_count << endl;
}