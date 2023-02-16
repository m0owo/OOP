#include "header.hpp"

double random_n() 
{
    Rand_double rnd{0, 500};
    std::random_device rd;
    rnd.seed(rd());
    float a = rnd();
    return a;
}

bool in_circle(float x, float y, float cx = 250, float cy = 250)
{
    return (sqrt(pow(x - cx, 2) + pow(y - cy, 2)) <= 250);
}
