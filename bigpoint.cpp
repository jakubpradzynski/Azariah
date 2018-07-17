#include "bigpoint.h"
#include <iostream>
#include <math.h>

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
    this->lightForce = 0.;
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
    this->lightForce = 0.;
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
    std::cout << "Light force: " << lightForce << std::endl;
}

void BigPoint::calculateLightForce(Light light)
{
    Vector3 l = Vector3(light.x - this->point3DAfterTransform.x, light.y -  this->point3DAfterTransform.y, light.z - this->point3DAfterTransform.z);
    double cosB = dotProductV3(this->normalVector, l) / calculateVectorLength(l);
    double lightForce = std::max((double)0, cosB);
    this->lightForce = lightForce;
}

double BigPoint::calculateVectorLength(Vector3 vector)
{
    return sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
}

double BigPoint::dotProductV3(Vector3 v1, Vector3 v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

BigPoint::~BigPoint()
{
    return;
}


