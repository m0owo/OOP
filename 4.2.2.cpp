#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iomanip>
using namespace std;

template <class T>
bool all_zeroes(const T& beg, const T& end) 
{
    vector<int> ret;
    auto out = back_inserter(ret);
    copy(beg, end, out);
    for (auto n: ret) {
        if (n != 0) {
            return false;
        }
    }
    return true;
}

int main() 
{
    cout << boolalpha;

    vector<int> vec1{1, 0, 2, 3};
    vector<int> vec2(10);
    bool z1 = all_zeroes(vec1.begin(), vec1.end());
    bool z2 = all_zeroes(vec2.begin(), vec2.end());
    cout << "z1 : " << z1 << endl;
    cout << "z2 : " << z2 << endl;

    list<int> li1(vec1.rbegin(), vec1.rend());
    list<int> li2(10);
    bool zz1 = all_zeroes(li1.begin(), li1.end());
    bool zz2 = all_zeroes(li2.begin(), li2.end());
    cout << "zz1 : " << zz1 << endl;
    cout << "zz2 : " << zz2 << endl;
}
