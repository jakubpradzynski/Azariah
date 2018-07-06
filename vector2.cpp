#include "vector2.h"
#include <iostream>

Vector2::Vector2()
{
    this->x = 0.;
    this->y = 0.;
}

Vector2::Vector2(double x, double y)
{
    this->x = x;
    this->y = y;
}

void Vector2::print()
{
    std::cout << "Vector2: [" << x << "," << y << "]" << std::endl;
}

Vector2::~Vector2()
{
    return;
}
