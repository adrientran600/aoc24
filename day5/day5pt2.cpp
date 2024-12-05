#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <cmath>
using namespace std;

void shift(vector<int> &update, int i, int j) {
    int temp = update[j];
    update.erase(update.begin() + j);
    i--;
    update.insert(update.begin() + i + 1, temp);
}

pair<int,int> checkOrder(vector<int> &update, unordered_map<int, set<int>> ordering_map) {
    for (int i = 1; i < update.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (ordering_map[update[i]].find(update[j]) != ordering_map[update[i]].end()) {
                return pair(i, j);
            }
        }
    }
    return pair(-1, -1);
}

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
        vector<int> update;
        for (int i = 0; i < input_line.length(); i += 3) {
            // cout << input_line.substr(i, 2) << " ";
            update.push_back(stoi(input_line.substr(i, 2)));
        }
        // cout << endl;

        pair<int, int> check = checkOrder(update, ordering_map);
        if (check.first != -1) {
            shift(update, check.first, check.second);
            check = checkOrder(update, ordering_map);
            while (check.first != -1) {
                shift(update, check.first, check.second);
                check = checkOrder(update, ordering_map);
            }
            sum += update[update.size()/2];
        }
    }
    
    file.close();

    cout << sum << endl;
}