/*
init sum
take input from user
for loop n times to draw random number from range [0, 1]
sum += random number - 0.5
sum divide by n
*/

#include <iostream>
#include "random.hpp"
#include <cmath>

double random_mine() {
    Rand_double rnd{0, 1};
    std::random_device rd;
    rnd.seed(rd());
    float a = rnd();
    return a;
}

int main() {
    float n;
    float sum;
    float random_n;
    float mean_squared_error;
    std::cout << "Enter N: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        random_n = random_mine();
        sum += pow((random_n - 0.5), 2);
    }

    mean_squared_error = (sum / n);
    std::cout << "The mean squared error is " << mean_squared_error;

}
