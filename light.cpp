#include "light.h"
#include <iostream>

Light::Light()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->color = RGB(255, 255, 255);
    this->isOn = false;
}

Light::Light(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->color = RGB(255, 255, 255);
    this->isOn = false;
}

void Light::print()
{
    std::cout << "Light: " << "[" << x << "," << y << "," << z << "]" << std::endl;
    color.print();
    std::cout << "Is on: " << isOn << std::endl;
}

Light::~Light()
{
    return;
}
