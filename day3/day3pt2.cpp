#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ifstream file("day3inp.txt");
    int sum = 0;

    string input_line;
    string line = "";
    while (getline (file, input_line)) {
        line += input_line;
    }
    cout << line << endl;
    
    bool doo = true;

    for (int i = 0; i < line.length(); i++) {
        char curr = line.at(i);
        if (curr == 'd') {
            if (line.substr(i, 4).compare("do()") == 0) {
                doo = true;
            } else if (line.substr(i, 7).compare("don't()") == 0) {
                doo = false;
            }
        }
        if (doo && curr == 'm') {
            int temp_curr = i + 4;
            string num1 = "";
            string num2 = "";
            if (line.substr(i, 4).compare("mul(") == 0) {
                // cout << line.at(temp_curr) << endl;
                while (isdigit(line.at(temp_curr))) {
                    num1 += line.at(temp_curr);
                    temp_curr++;
                }
                if (line.at(temp_curr) == ',') {
                    temp_curr++;
                    while (isdigit(line.at(temp_curr))) {
                        num2 += line.at(temp_curr);
                        temp_curr++;
                    }
                }
                if (line.at(temp_curr) == ')') {
                    // cout << num1 << " " << num2 << endl;
                    sum += stoi(num1) * stoi(num2);
                }
            }
        }
    }
    file.close();

    cout << sum << endl;
}