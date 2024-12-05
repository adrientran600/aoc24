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

    ifstream file("ordering.txt");
    string input_line;

    unordered_map<int, set<int>> ordering_map;
    while (getline (file, input_line)) {
        int num1 = stoi(input_line.substr(0, 2));
        int num2 = stoi(input_line.substr(3, 2));
        // cout << num1 << " " << num2 << endl;
        ordering_map[num1].insert(num2);
    }

    ifstream updates("updates.txt");
    while (getline (updates, input_line)) {
        bool correct = true;
        vector<int> update;
        for (int i = 0; i < input_line.length(); i += 3) {
            // cout << input_line.substr(i, 2) << " ";
            update.push_back(stoi(input_line.substr(i, 2)));
        }
        // cout << endl;

        for (int i = 1; i < update.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (ordering_map[update[i]].find(update[j]) != ordering_map[update[i]].end()) {
                    correct = false;
                    break;
                }
            }
        }

        if (correct) {
            sum += update[update.size()/2];
        }
    }

    
    file.close();

    cout << sum << endl;
}