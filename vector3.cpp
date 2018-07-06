#include "vector3.h"
#include <iostream>

Vector3::Vector3()
{
    this->x = 0.;
    this->y = 0.;
    this->z = 0.;
}

Vector3::Vector3(char *facet)
{
    char f1[4] = {facet[0],
                  facet[1],facet[2],facet[3]};

    char f2[4] = {facet[4],
                  facet[5],facet[6],facet[7]};

    char f3[4] = {facet[8],
                  facet[9],facet[10],facet[11]};

    float xx = *((float*) f1 );
    float yy = *((float*) f2 );
    float zz = *((float*) f3 );

    this->x = double(xx);
    this->y = double(yy);
    this->z = double(zz);
}

Vector3::Vector3(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vector3::print()
{
    std::cout << "Vector3: [" << x << "," << y << "," << z << "]" << std::endl;
}

Vector3::~Vector3()
{

}
