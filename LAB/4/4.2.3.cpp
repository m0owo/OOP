#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

template <class T>
string str_join(string separator, const T& beg, const T& end) {
    vector<string> ret;
    auto out = back_inserter(ret);
    copy(beg, end, out);
    string str;
    for (auto n: ret) {
        str += n;
        str += separator;
    }
    str = str.substr(0, str.size() - separator.size());
    return str;
}

int main() {
    auto words = vector<string>{"C", "Rust", "C++", "Python"};
    auto str1 = str_join(string(", "), words.begin(), words.end());
    cout << "str1: " << str1 << endl;

    auto words2 = list<string>(words.rbegin(), words.rend());
    auto str2 = str_join(string(", "), words2.begin(), words2.end());
    cout << "str2: " << str2 << endl; 
}
