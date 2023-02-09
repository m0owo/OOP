#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

float sort_erase(vector<string> scores) {
    float highest;
    for (string score: scores) {
        if (stof(score) > highest) {
            highest = stof(score);
        }
    }
    return highest;
}

void print_vec(vector<string> scores) {
    cout << scores[0];
    for (int i = 1; i < scores.size(); ++i) {
        cout << " " << scores[i];
    }
    cout << endl;
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

    for (auto const& x : scores_map) {
        cout << x.first << ": ";
        cout << sort_erase(x.second) << endl;
    }
    
}

/*
Leo 5000 1200 2000 4500
Mike 3800 2400 3200
Raph 1500 2200 1200 4000 4800
Don 5000 1600 3200 4600
May 4400 3300 5800
*/
