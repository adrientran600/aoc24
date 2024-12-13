#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <cmath>
using namespace std;

int main() {
    unsigned long long total = 0;
    ifstream file("day11inp.txt");
    string input_line;

    vector<long long> past_stones;
    vector<long long> new_stones;

    while (getline (file, input_line)) {
        stringstream ss(input_line);
        int rock;
        while (ss >> rock) {
            new_stones.push_back(rock);
        }
    }
    file.close();
        
    for (int i = 0; i < 25; i++) {
        past_stones = new_stones;
        new_stones.clear();

        // for (long long x : past_stones) {
        //     cout << x << " ";
        // }
        // cout << endl;

        for (long long x : past_stones) {
            string s = to_string(x);
            if (x == 0) {
                new_stones.push_back(1);
            } else if (s.length()%2 == 0) {
                new_stones.push_back(stol(s.substr(0, s.length()/2)));
                new_stones.push_back(stol(s.substr(s.length()/2, s.length())));
            } else {
                new_stones.push_back(x*2024);
            }
        }
    }

    cout << new_stones.size() << endl;
}