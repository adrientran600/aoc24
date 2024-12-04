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
            int prev = 0;
            int curr = table[r][c];

            // right
            int i = 1;
            while (c < table[0].size() - 3 && curr == prev + 1) {
                // cout << "running" << endl;
                if (curr == 4) {
                    xmax_count++;
                    break;
                }
                prev = curr;
                curr = table[r][c + i];
                i++;
                // cout << "prev: " << prev << " curr: " << curr << " " << r << c << endl;
            }
            // down right
            prev = 0;
            curr = table[r][c];
            i = 1;
            while (r < table.size() - 3 && c < table[0].size() - 3 && curr == prev + 1) {
                // cout << "running" << endl;
                if (curr == 4) {
                    xmax_count++;
                    break;
                }
                prev = curr;
                curr = table[r + i][c + i];
                i++;
                // cout << "prev: " << prev << " curr: " << curr << " " << r << c << endl;
            }
            // down
            prev = 0;
            curr = table[r][c];
            i = 1;
            while (r < table.size() - 3 && curr == prev + 1) {
                // cout << "running" << endl;
                if (curr == 4) {
                    xmax_count++;
                    break;
                }
                prev = curr;
                curr = table[r + i][c];
                i++;
                // cout << "prev: " << prev << " curr: " << curr << " " << r << c << endl;
            }
            // down left
            prev = 0;
            curr = table[r][c];
            i = 1;
            while (r < table.size() - 3 && c >= 3 && curr == prev + 1) {
                // cout << "running" << endl;
                if (curr == 4) {
                    xmax_count++;
                    break;
                }
                prev = curr;
                curr = table[r + i][c - i];
                i++;
                // cout << "prev: " << prev << " curr: " << curr << " " << r << c << endl;
            }
            // left
            prev = 0;
            curr = table[r][c];
            i = 1;
            while (c >= 3 && curr == prev + 1) {
                // cout << "running" << endl;
                if (curr == 4) {
                    xmax_count++;
                    break;
                }
                prev = curr;
                curr = table[r][c - i];
                i++;
                // cout << "prev: " << prev << " curr: " << curr << " " << r << c << endl;
            }
            // up left
            prev = 0;
            curr = table[r][c];
            i = 1;
            while (r >= 3 && c >= 3 && curr == prev + 1) {
                // cout << "running" << endl;
                if (curr == 4) {
                    xmax_count++;
                    break;
                }
                prev = curr;
                curr = table[r - i][c - i];
                i++;
                // cout << "prev: " << prev << " curr: " << curr << " " << r << c << endl;
            }
            // up
            prev = 0;
            curr = table[r][c];
            i = 1;
            while (r >= 3 && curr == prev + 1) {
                // cout << "running" << endl;
                if (curr == 4) {
                    xmax_count++;
                    break;
                }
                prev = curr;
                curr = table[r - i][c];
                i++;
                // cout << "prev: " << prev << " curr: " << curr << " " << r << c << endl;
            }
            // up right
            prev = 0;
            curr = table[r][c];
            i = 1;
            while (r >= 3 && c < table[0].size() - 3 && curr == prev + 1) {
                // cout << "running" << endl;
                if (curr == 4) {
                    xmax_count++;
                    break;
                }
                prev = curr;
                curr = table[r - i][c + i];
                i++;
                // cout << "prev: " << prev << " curr: " << curr << " " << r << c << endl;
            }
        }
    }

    
    cout << xmax_count << endl;
}