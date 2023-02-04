#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> unstylize(const vector<string> &words) {
    for (string word: words) {
        if (word.size() < 2 || word[0] != '*' || word[word.size() - 1] != '*') {
            continue;
        } else {
            word = word.substr(1, word.size() - 2);
        }
    }
}

int main() {
    cout << "Hello World" << endl;
}

