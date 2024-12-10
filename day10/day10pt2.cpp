#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <cmath>
using namespace std;

void explore(int r, int c, vector<vector<int>>& topo, vector<pair<int, int>>& visited) {
    int curr = topo[r][c];
    if (curr == 9) {
        visited.push_back(pair<int,int>(r,c));
        return;
    }
    if (r > 0 && topo[r - 1][c] == curr + 1) {
        explore(r - 1, c, topo, visited);
    }
    if (r < topo.size() - 1 && topo[r + 1][c] == curr + 1) {
        explore(r + 1, c, topo, visited);
    }
    if (c > 0 && topo[r][c - 1] == curr + 1) {
        explore(r, c - 1, topo, visited);
    }
    if (c < topo[0].size() - 1 && topo[r][c + 1] == curr + 1) {
        explore(r, c + 1, topo, visited);
    }
    return;
}

int main() {
    int total = 0;
    ifstream file("day10inp.txt");
    string input_line;

    vector<vector<int>> topo(45);
    set<pair<int, int>> heads;

    int c = 0;
    while (getline (file, input_line)) {
        for (int i = 0; i < input_line.length(); i++) {
            topo[c].push_back(input_line.at(i) - '0');
            if (input_line.at(i) - '0' == 0) {
                heads.insert(pair<int,int>(c,i));
            } 
        }
        c++;
    }
    file.close();
        
    for (auto elem : heads) {
        vector<pair<int, int>> visited; 
        explore(elem.first, elem.second, topo, visited);
        total += visited.size();
    }

    cout << total << endl;
}