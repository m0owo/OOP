#include <iostream>
#include <list>
#include <vector>
#include <iterator>
using namespace std;

template <class T>
T remove_negative(const T& input )
{
    T output;
    for (auto x: input) {
        if (x < 0) {
            output.push_back(x);
        }
    }
    return output;
}

template <class T>
void print(const T& output, string name) {
    cout << name << endl;
    for (auto x: output) {
        cout << " " << x;
    }
    cout << endl;
}

int main() 
{
    vector<double> vec1{0.8, -5.1, 1.6, -6.5, 10.5};
    auto vec2 = remove_negative(vec1);
    print(vec1, "vec1");
    print(vec2, "vec2");

    list<double> li1(vec1.rbegin(), vec1.rend());
    auto li2 = remove_negative(li1);
    print(li1, "li1");
    print(li2, "li2");
}
