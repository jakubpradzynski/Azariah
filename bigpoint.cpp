#include "bigpoint.h"
#include <iostream>

BigPoint::BigPoint()
{
    this->point3D = Vector3();
    this->point3DAfterTransform = Vector3();
    this->point2D = Vector2();
    this->color = RGB();
    this->pointUV = Vector2();
    this->normalVector = Vector3();
    this->vector = Vector3();
    this->vectorLength = 0.;
}

BigPoint::BigPoint(Vector3 point3D)
{
    this->point3D = point3D;
    this->point3DAfterTransform = Vector3();
    this->point2D = Vector2();
    this->color = RGB();
    this->pointUV = Vector2();
    this->normalVector = Vector3();
    this->vector = Vector3();
    this->vectorLength = 0.;
}

void BigPoint::print()
{
    std::cout << "Big point:" << std::endl;
    std::cout << "Point 3D: (" << point3D.x << "," << point3D.y << "," << point3D.z << ")" << std::endl;
    std::cout << "Point 3D after transform: (" << point3DAfterTransform.x << "," << point3DAfterTransform.y << "," << point3DAfterTransform.z << ")" << std::endl;
    std::cout << "Point 2D: (" << point2D.x << "," << point2D.y << ")" << std::endl;
    std::cout << "Color: (" << color.r << "," << color.g << "," << color.b << ")" << std::endl;
    std::cout << "Point UV: (" << pointUV.x << "," << pointUV.y << ")" << std::endl;
    std::cout << "Normal vector: [" << normalVector.x << "," << normalVector.y << "," << normalVector.z << "]" << std::endl;
    std::cout << "Vector: [" << vector.x << "," << vector.y << "," << vector.z << "]" << std::endl;
    std::cout << "Vector length: " << vectorLength << std::endl;
}

BigPoint::~BigPoint()
{
    return;
}


