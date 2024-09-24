//
// Created by josep on 24/09/2024.
//
#include <vector>

using namespace std;
#include "map"
#include "iostream"

int findMode(vector<int> nums) {
    map<int, int>numberFrequencies;

    for (int i = 0; i < nums.size(); i++) {
        if (numberFrequencies.count(nums[i])) {
            numberFrequencies.at(nums[i])++;
        }
        else {
            numberFrequencies.insert({nums[i], 1});
        }
    }

    int modeIndex = 0;
    int modeFreq = 0;

    for (auto i : numberFrequencies) {
        if (i.second > modeFreq) {
            modeIndex = i.first;
            modeFreq = i.second;
        }
    }

    return modeIndex;

}


int main() {

    vector<int> a = {3,2,1,5,3,6,7,1,2};

    cout << findMode(a);
}