#include "rgb.h"
#include <iostream>

RGB::RGB()
{
    this->r = 0;
    this->g = 0;
    this->b = 0;
}

RGB::RGB(int r, int g, int b)
{
    this->r = r % 256;
    this->g = g % 256;
    this->b = b % 256;
}

RGB::RGB(double r, double g, double b)
{
    this->r = (int)r % 256;
    this->g = (int)g % 256;
    this->b = (int)b % 256;
}

void RGB::print()
{
    std::cout << "RGB: (" << r << "," << g << "," << b << ")" << std::endl;
}

RGB::~RGB()
{
    return;
}
