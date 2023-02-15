#include <iostream>
using namespace std;

bool is_prime(int n)
{
    if ( (n % 2 == 0) && (n != 2) || (n % 3 == 0) && (n != 3) ) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0) {
            return false; // n is divisible by i or i + 2
        }
    }
    return true; // no divisor within [5, n) found
}
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    cout << "Enter the upper limit: ";
    int n;
    cin >> n;
    for (int i = 2; i <= n; i += 1) {
        if (is_prime(i))
        cout << i << endl;
    }
    return 0;
}
