#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    vector<vector<int>> table(140);
    unordered_map<char, int> map = {
        {'X', 1},
        {'M', 2},
        {'A', 3},
        {'S', 4},
    };
    int xmax_count = 0;;

    ifstream file("day4inp.txt");

    string line;
    int row = 0;
    while (getline (file, line)) {
        for (int col = 0; col < line.length(); col++) {
            table.at(row).push_back(map[line.at(col)]);
            // cout << table[row][col];
        }
        // cout << endl;
        row++;
    }
    file.close();

    for (int r = 0; r < table.size(); r++) {
        for (int c = 0; c < table[0].size(); c++) {
            // cout << r << " " << c << " " << endl;
            int curr = table[r][c];

            if (c != 0 && r != 0 && r != table.size() - 1 && c != table[0].size() - 1 && curr == 3) {
                if (table[r + 1][c + 1] == 2 && table[r + 1][c - 1] == 2) { // down
                    if (table[r - 1][c + 1] == 4 && table[r - 1][c - 1] == 4) {
                        xmax_count++;
                    }
                } else if (table[r - 1][c - 1] == 2 && table[r + 1][c - 1] == 2) { // left
                    if (table[r - 1][c + 1] == 4 && table[r + 1][c + 1] == 4) {
                        xmax_count++;
                    }
                } else if (table[r - 1][c + 1] == 2 && table[r - 1][c - 1] == 2) { // up
                    if (table[r + 1][c - 1] == 4 && table[r + 1][c + 1] == 4) {
                        xmax_count++;
                    }
                } else if (table[r - 1][c + 1] == 2 && table[r + 1][c + 1] == 2) { // right
                    if (table[r - 1][c - 1] == 4 && table[r + 1][c - 1] == 4) {
                        xmax_count++;
                    }
                }
                
                
            }
        }
    }

    
    cout << xmax_count << endl;
}