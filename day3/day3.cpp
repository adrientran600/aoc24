#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ifstream file("altinp.txt");
    int sum = 0;

    string input_line;
    string line = "";
    while (getline (file, input_line)) {
        line += input_line;
    }
    cout << line << endl;
    while(line.length() > 0) {
        // cout << line << endl;
        int start = line.find("mul(");
        int dont = line.find("don't()");
        int doo = line.find("do()");
        // cout << "start: " << start << endl;
        // cout << "dont: " << dont << endl;
        // cout << "do: " << doo << endl;

        if (dont != string::npos && dont < start) {
            line.erase(line.begin() + dont, line.begin() + 6);
            int temp_dont = line.find("don't()");
            while (temp_dont != string::npos && temp_dont < start) {
                // cout << "dont: " << temp_dont << endl;
                dont = temp_dont;
                line.erase(line.begin() + dont, line.begin() + dont + 6);
                temp_dont = line.find("don't()");
            }
        }
        if (doo != string::npos && doo < start) {
            line.erase(line.begin() + doo, line.begin() + 3);
            int temp_doo = line.find("do()");
            while (temp_doo != string::npos && temp_doo < start) {
                // cout << "do: " << temp_doo << endl;
                doo = temp_doo;
                line.erase(line.begin() + doo, line.begin() + doo + 3);
                temp_doo = line.find("do()");
            }
        }

        // cout << doo  << " " << dont << endl;
        if (dont == string::npos || (dont > start) || (doo != string::npos && doo < start && doo > dont)) {
            // cout << "running" << endl;
            if (start == string::npos) break;
            int start = line.find("mul(");
            line.erase(line.begin(), line.begin() + start);
            // cout << "start: " << start << endl;

            int curr = 4;
            if (isdigit(line.at(curr))) {
                string num1 = "";
                string num2 = "";
                while (isdigit(line.at(curr))) {
                    num1 += line.at(curr);
                    curr++;
                }
                if (line.at(curr) == ',') {
                    curr++;
                    while (isdigit(line.at(curr))) {
                        num2 += line.at(curr);
                        curr++;
                    }
                    if (line.at(curr) == ')') {
                        // Found correct formatting
                        sum += stoi(num1) * stoi(num2);
                        line.erase(line.begin(), line.begin() + curr);
                    } else {
                        line.erase(line.begin(), line.begin() + curr);
                    }
                } else {
                    line.erase(line.begin(), line.begin() + curr);
                }
            } else {
                line.erase(line.begin(), line.begin() + curr);
            }
        } else {
            line.erase(line.begin(), line.begin() + start + 4);
        }
    }
    file.close();

    cout << sum << endl;
}