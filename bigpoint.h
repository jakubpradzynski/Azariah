#ifndef BIGPOINT_H
#define BIGPOINT_H

#include "vector3.h"
#include "rgb.h"
#include "vector2.h"

class BigPoint
{
public:
    BigPoint();
    BigPoint(Vector3 point3D);
    void print();
    ~BigPoint();

    Vector3 point3D; // Point coordinates from stl file
    Vector3 point3DAfterTransform; // Point coordinates after multiply by transformation matrix
    Vector2 point2D; // Point coordinates after perspective projection
    RGB color; // Point color
    Vector2 pointUV; // U V data for texturing
    Vector3 normalVector; // Normal vector of this point in triangle
    Vector3 vector; // Vector before normalization
    double vectorLength; // Vector length
};

#endif // POINT_H
