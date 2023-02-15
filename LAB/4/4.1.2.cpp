#include <iostream>
#include <vector>
using std::sort;
using std::vector;
using namespace std;

template <class T>
T median(std::vector<T> vec)
{
    sort(vec.begin(), vec.end());
    const auto size = vec.size();
    const auto mid = size / 2;
    if (vec.size() == 0) {
        return 0;
    }
    return size % 2 != 0? (vec[mid] + vec[mid + 1]) / 2: vec[mid];
}

int main() {
    vector<int> test_vec{1, 2, 3, 4, 5};
    cout << median(test_vec) << endl;
    return 0;
}
