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
    long long total = 0;
    
    ifstream file("day7inp.txt");
    string input_line;

    vector<vector<long>> nums(850);

    int c = 0;
    while (getline (file, input_line)) {
        stringstream ss(input_line);

        string curr;
        ss >> curr;

        nums[c].push_back(stol(curr.substr(0, curr.length() - 1)));
        while (ss >> curr) {
            // cout << curr << " ";
            nums[c].push_back(stol(curr));
        }
        // cout << endl;
        c++;
    }
    // cout << c;

    
    for (int i = 0; i < nums.size(); i++) {
        vector<bool> add(nums[i].size() - 2, false);
        bool found = false;
        long long sum = nums[i][1];

        for (int j = 2; j < nums[i].size(); j++) {
            sum *= nums[i][j];
        }
        if (sum == nums[i][0]) {
            total += sum;
            // cout << "all mult: " <<  sum << endl;
        } else {
            // for (bool boo : add) {
            //     cout << boo << " ";
            // }
            // cout << endl;

            while(!update(add)) {
                // for (bool boo : add) {
                //     cout << boo << " ";
                // }
                // cout << endl;

                sum = nums[i][1];
                for (int j = 2; j < nums[i].size(); j++) {
                    if (add[j-2]) {
                        sum += nums[i][j];
                    } else {
                        sum *= nums[i][j];
                    }
                }
                if (sum == nums[i][0]) {
                    // cout << sum << endl;
                    total += sum;
                    found = true;
                    break;
                }
            }
            if (!found) {
                sum = nums[i][1];
                // cout << "curr sum: " << sum << endl;
                for (int j = 2; j < nums[i].size(); j++) {
                    sum += nums[i][j];
                }
                // cout << "end sum all add: " << sum << endl;
                if (sum == nums[i][0]) {
                    // cout << sum << endl;
                    total += sum;
                }
            }
            
            // cout << endl;
        }

        
    }

    // for (vector<int> vec : nums) {
    //     for (int x : vec) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

    file.close();

    cout << total << endl;
}