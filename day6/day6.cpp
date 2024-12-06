#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <cmath>
using namespace std;

int main() {
    int sum = 0;
    vector<vector<int>> map(130);
    ifstream file("day6inp.txt");
    string input_line;

    unordered_map<string, string> change_dir = {
        {"up", "right"},
        {"right", "down"},
        {"down", "left"},
        {"left", "up"},
    };

    unordered_map<string, pair<int,int>> dir_val = {
        {"up", {-1, 0}},
        {"right", {0, 1}},
        {"down", {1, 0}},
        {"left", {0, -1}},
    };

    int i = 0;
    pair<int,int> pos(0, 0);
    while (getline (file, input_line)) {
        for (int j = 0; j < input_line.length(); j++) {
            if (input_line.at(j) == '.') {
                map[i].push_back(0);
            } else if (input_line.at(j) == '#') {
                map[i].push_back(1);
            } else {
                map[i].push_back(2);
                pos = {i, j};
            }
        }
        i++;
    }

    for (vector<int> row : map) {
        for (int x : row) {
            cout << x;
        }
        cout << endl;
    }

    sum++;
    bool notbound = false;
    pair<int,int> prev_pos = pos;
    string dir = "up";
    pair<int, int> val = dir_val[dir];
    pair<int,int> next_pos(pos.first + val.first, pos.second + val.second);
    // cout << next_pos.first << " " << next_pos.second << endl;
    // cout << val.first << " " << val.second << endl;
    while (notbound || (next_pos.first > 0 && next_pos.first < map.size() - 1 && next_pos.second > 0 && next_pos.second < map[0].size() - 1)) {
        notbound = false;
        cout << pos.first << " " << pos.second << endl;
        cout << next_pos.first << " " << next_pos.second << endl;
        
        if (map[next_pos.first][next_pos.second] == 1) {
            dir = change_dir[dir];
            val = dir_val[dir];
        } else {
            if (map[pos.first][pos.second] != 2) {
                sum++;
            }
            map[pos.first][pos.second] = 2;
            pos = next_pos;
        }
        next_pos = {pos.first + val.first, pos.second + val.second};

        if (map[next_pos.first][next_pos.second] == 1) {
            notbound = true;
        }

        // for (vector<int> row : map) {
        //     for (int x : row) {
        //         cout << x;
        //     }
        //     cout << endl;
        // }
        // cout << endl;

    }
    sum += 2;
    

    // for (vector<int> row : map) {
    //     for (int x : row) {
    //         cout << x;
    //     }
    //     cout << endl;
    // }

    // cout << pos.first << " " << pos.second << endl;
    
    file.close();

    cout << sum << endl;
}