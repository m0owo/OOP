// #include "header.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

float highest(vector<string> scores) {
    float highest = stof(scores[0]);
    for (string score: scores) {
        if (stof(score) > highest) {
            highest = stof(score);
        }
    }
    return highest;
}

int main() {
    vector<string> scores_vec;
    map<string, vector<string>> scores_map;
    string input;
    string tmp;

    cout << "Score Sheet: " << endl;
    for (int i = 0; i < 5; ++i) {
        getline(cin, input);
        stringstream stream(input);
        while (getline(stream, tmp, ' ')) {
            scores_vec.push_back(tmp);
        }
        string name = scores_vec[0];
        scores_vec.erase(scores_vec.begin());
        scores_map[name] = scores_vec;
        scores_vec.clear();
    }


    map<float, vector<string>> highest_scores;
    int rank = 1;
    for (auto const& x : scores_map) {
        highest_scores[highest(x.second)].push_back(x.first);
    }
    for (auto x : highest_scores) {
        sort(x.second.begin(), x.second.end(), greater<string>());
    }
    cout << "\nMax Score Rankings: " << endl;
    for(auto it = highest_scores.rbegin(); it != highest_scores.rend(); ++it) {
        for (auto name: it->second) {
            cout << rank << ". " << name << " " << it->first << endl;
            ++rank;
        }
    }
    
}

/*
Leo 5000 1200 2000 4500
Mike 3800 2400 3200
Raph 1500 2200 1200 4000 4800
Don 5000 1600 3200 4600
May 4400 3300 5800
*/
