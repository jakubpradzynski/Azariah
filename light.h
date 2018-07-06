#ifndef LIGHT_H
#define LIGHT_H

#include "rgb.h"

class Light
{
public:
    Light();
    Light(double x, double y, double z);
    void print();
    ~Light();

    double x, y, z;
    RGB color;
    bool isOn;
};

#endif // LIGHT_H
