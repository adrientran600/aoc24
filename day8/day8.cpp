#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <cmath>
using namespace std;

bool update(vector<bool> &add) {
    bool alltrue = true;

    for (int i = 0; i < add.size(); i++) {
        if (add[i]) {
            add[i] = false;
        } else if (!add[i]) {
            add[i] = true;
            alltrue = false;
            break;
        }
    }
    return alltrue;
}

int main() {
    int total = 0;
    int bound = 50;
    ifstream file("day8inp.txt");
    string input_line;

    unordered_map<char, vector<pair<int, int>>> map;
    set<pair<int, int>> antinodes;

    int c = 0;
    while (getline (file, input_line)) {
        for (int j = 0; j < input_line.length(); j++) {
            if (input_line.at(j) != '.') {
                map[input_line.at(j)].push_back(pair<int,int>(c, j));
            } 
        }
        c++;
    }

    for (auto elem : map) {
        vector<pair<int, int>> coords = elem.second;
        
        for (int i = 0; i < coords.size(); i++) {
            for (int j = i + 1; j < coords.size(); j++) {
                // cout << i << " " << j << endl;
                pair<int, int> offset(abs(coords[i].first - coords[j].first), abs(coords[i].second - coords[j].second));
                double slope = (double)(-coords[i].first + coords[j].first)/(coords[i].second - coords[j].second);
                // cout << "slope: " <<  slope << endl;

                if (slope < 0) {
                    if (coords[i].first < coords[j].first) {
                        pair<int, int> AN_first(coords[i].first - offset.first, coords[i].second - offset.second);
                        if (AN_first.first >= 0 && AN_first.second >= 0 && AN_first.first < bound && AN_first.second < bound) {
                            antinodes.insert(AN_first);
                            // cout << coords[i].first << " " << coords[i].second <<  " , " << coords[j].first <<  " " << coords[j].second <<  " : " << AN_first.first <<  " " << AN_first.second << endl;

                        }
                        pair<int, int> AN_second(coords[j].first + offset.first, coords[j].second + offset.second);
                        if (AN_second.first >= 0 && AN_second.second >= 0 && AN_second.first < bound && AN_second.second < bound) {
                            antinodes.insert(AN_second);
                            // cout << coords[i].first << " " << coords[i].second <<  " , " << coords[j].first <<  " " << coords[j].second <<  " : " << AN_second.first <<  " " << AN_second.second << endl;
                        }
                    } else {
                        pair<int, int> AN_first(coords[i].first + offset.first, coords[i].second + offset.second);
                        if (AN_first.first >= 0 && AN_first.second >= 0 && AN_first.first < bound && AN_first.second < bound) {
                            antinodes.insert(AN_first);
                            // cout << coords[i].first << " " << coords[i].second <<  " , " << coords[j].first <<  " " << coords[j].second <<  " : " << AN_first.first <<  " " << AN_first.second << endl;
                        }
                        pair<int, int> AN_second(coords[j].first - offset.first, coords[j].second - offset.second);
                        if (AN_second.first >= 0 && AN_second.second >= 0 && AN_second.first < bound && AN_second.second < bound) {
                            antinodes.insert(AN_second);
                            // cout << coords[i].first << " " << coords[i].second <<  " , " << coords[j].first <<  " " << coords[j].second <<  " : " << AN_second.first <<  " " << AN_second.second << endl;
                        }
                    }
                } else if (slope > 0) {
                    if (coords[i].first < coords[j].first) {
                        pair<int, int> AN_first(coords[i].first - offset.first, coords[i].second + offset.second);
                        if (AN_first.first >= 0 && AN_first.second >= 0 && AN_first.first < bound && AN_first.second < bound) {
                            antinodes.insert(AN_first);
                            // cout << coords[i].first << " " << coords[i].second <<  " , " << coords[j].first <<  " " << coords[j].second <<  " : " << AN_first.first <<  " " << AN_first.second << endl;

                        }
                        pair<int, int> AN_second(coords[j].first + offset.first, coords[j].second - offset.second);
                        if (AN_second.first >= 0 && AN_second.second >= 0 && AN_second.first < bound && AN_second.second < bound) {
                            antinodes.insert(AN_second);
                            // cout << coords[i].first << " " << coords[i].second <<  " , " << coords[j].first <<  " " << coords[j].second <<  " : " << AN_second.first <<  " " << AN_second.second << endl;
                        }
                    } else {
                        pair<int, int> AN_first(coords[i].first + offset.first, coords[i].second - offset.second);
                        if (AN_first.first >= 0 && AN_first.second >= 0 && AN_first.first < bound && AN_first.second < bound) {
                            antinodes.insert(AN_first);
                            // cout << coords[i].first << " " << coords[i].second <<  " , " << coords[j].first <<  " " << coords[j].second <<  " : " << AN_first.first <<  " " << AN_first.second << endl;
                        }   
                        pair<int, int> AN_second(coords[j].first - offset.first, coords[j].second + offset.second);
                        if (AN_second.first >= 0 && AN_second.second >= 0 && AN_second.first < bound && AN_second.second < bound) {
                            antinodes.insert(AN_second);
                            // cout << coords[i].first << " " << coords[i].second <<  " , " << coords[j].first <<  " " << coords[j].second <<  " : " << AN_second.first <<  " " << AN_second.second << endl;
                        }
                    }
                } else if (slope == 0) {

                }

                // cout << endl;
            }
        }
    }
        
    file.close();

    // for (auto elem : antinodes) {
    //     cout << elem.first << " " << elem.second << endl;
    // }

    cout << antinodes.size() << endl;
}