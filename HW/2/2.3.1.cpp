#include <iostream>
#include <random.hpp>
#include <cmath>

double random_n() 
{
    Rand_double rnd{0, 1};
    std::random_device rd;
    rnd.seed(rd());
    float a = rnd();
    return a;
}

float calc_dist(float cx = 250, float cy = 250, float x, float y)
{
    return 0;
}

int main() 
{
    int n;
    std::cout << "Number of Points: ";
    std::cin >> n;
    return 0;
}
