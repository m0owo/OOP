#include "header.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include "random.hpp"

double random_n() 
{
    Rand_double rnd{0, 500};
    std::random_device rd;
    rnd.seed(rd());
    float a = rnd();
    return a;
}

bool in_circle(float x, float y)
{
    int c = 250;
    return (sqrt(pow(x - c, 2) + pow(y - c, 2)) <= 250);
}
