#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> unstylize(vector<string> &words) {
    for (int i = 0; i < words.size(); ++i) {
        if (words[i].size() > 1 && words[i].front() == '*' && words[i].back() == '*') {
            words[i].erase(0, 1);
            words[i].erase(words[i].size() - 1, 1);
        }
    }
    return words;
}

void print_vec(vector<string> vec) {
    for (int i = vec.size() - 1; i >= 0; --i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<string> input_vec = {};
    string input;
    string tmp;

    cout << "Input: ";
    getline(std::cin, input);
    stringstream stream(input);
    while(getline(stream, tmp, ' ')) {
        input_vec.push_back(tmp);
    }
    
    cout << "Output: ";
    vector<string> output_vec = unstylize(input_vec);
    unstylize(input_vec);
    print_vec(input_vec);
}

//C *C++* Rust* *Python* * *Java 
