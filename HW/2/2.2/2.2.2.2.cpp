#include "header.hpp"

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


    map<float, vector<string>> avg_scores;
    int rank = 1;
    for (auto const& x : scores_map) {
        avg_scores[average(x.second)].push_back(x.first);
    }
    for (auto x : avg_scores) {
        sort(x.second.begin(), x.second.end(), greater<string>());
    }
    cout << "\nAverage Score Rankings: " << endl;
    for(auto it = avg_scores.rbegin(); it != avg_scores.rend(); ++it) {
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
