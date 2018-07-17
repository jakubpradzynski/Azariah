#include "triangle.h"
#include <iostream>
#include "math.h"

Triangle::Triangle()
{
    this->p1 = BigPoint();
    this->p2 = BigPoint();
    this->p3 = BigPoint();
}

Triangle::Triangle(Vector3 p1, Vector3 p2, Vector3 p3)
{
    this->normalVector = Vector3();
    this->p1 = BigPoint(p1);
    this->p2 = BigPoint(p2);
    this->p3 = BigPoint(p3);
}

Triangle::Triangle(Vector3 normal, Vector3 p1, Vector3 p2, Vector3 p3)
{
    this->normalVector = normal;
    this->p1 = BigPoint(p1);
    this->p2 = BigPoint(p2);
    this->p3 = BigPoint(p3);
}

Triangle::Triangle(BigPoint p1, BigPoint p2, BigPoint p3)
{
    this->normalVector = Vector3();
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

Triangle::Triangle(Vector3 normal, BigPoint p1, BigPoint p2, BigPoint p3)
{
    this->normalVector = normal;
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

BigPoint Triangle::calculateMeanPoint()
{
    BigPoint bg = BigPoint();
    bg.point3D = Vector3((p1.point3D.x + p2.point3D.x + p3.point3D.x) / 3, (p1.point3D.x + p2.point3D.x + p3.point3D.x) / 3, (p1.point3D.x + p2.point3D.x + p3.point3D.x) / 3);
    bg.normalVector = normalVector;
    bg.color = p1.color;
    return bg;
}

Vector3 Triangle::calculateNormalVector()
{
    if (normalVector.x == 0 && normalVector.y == 0 && normalVector.z == 0) {
        Vector3 v = calculateVectorForPoint(1, *this);
        return v;
    }
    return normalVector;
}

void Triangle::print()
{
    std::cout << "Triangle points:" << std::endl;
    p1.print();
    p2.print();
    p3.print();
    std::cout << "Triangle mean point:" << std::endl;
    meanPoint.print();
    std::cout << "Triangle normal vector:" << std::endl;
    normalVector.print();
}

void Triangle::fillData()
{
    this->meanPoint = calculateMeanPoint();
    if (normalVector.x == 0 && normalVector.y == 0 && normalVector.z == 0) {
        this->normalVector = calculateNormalVector();
    }
    fillPointsVectorData();
}

void Triangle::fillPointsVectorData()
{
//    p1.vector = calculateVectorForPoint(1, *this);
//    p2.vector = calculateVectorForPoint(2, *this);
//    p3.vector = calculateVectorForPoint(3, *this);

//    p1.vectorLength = vectorLength(p1.vector);
//    p2.vectorLength = vectorLength(p2.vector);
//    p3.vectorLength = vectorLength(p3.vector);

//    p1.normalVector = normalizeVector(p1.vector);
//    p2.normalVector = normalizeVector(p2.vector);
//    p3.normalVector = normalizeVector(p3.vector);

      p1.normalVector = this->normalVector;
      p2.normalVector = this->normalVector;
      p3.normalVector = this->normalVector;
}

void Triangle::fillColorInPoints(RGB color)
{
    p1.color = color;
    p2.color = color;
    p3.color = color;
}

double Triangle::vectorLength(Vector3 vector)
{
    return sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
}

Vector3 Triangle::normalizeVector(Vector3 vector)
{
    double length = vectorLength(vector);
    return Vector3(vector.x / length, vector.y / length, vector.z / length);
}

Vector3 Triangle::calculateVectorForPoint(int pointNumber, Triangle triangle)
{
    switch (pointNumber) {
    case 1:
        return crossProduct(calculateVector(triangle.p1.point3D, triangle.p2.point3D), calculateVector(triangle.p1.point3D, triangle.p3.point3D));
        break;
    case 2:
        return crossProduct(calculateVector(triangle.p2.point3D, triangle.p1.point3D), calculateVector(triangle.p2.point3D, triangle.p3.point3D));
        break;
    case 3:
        return crossProduct(calculateVector(triangle.p3.point3D, triangle.p1.point3D), calculateVector(triangle.p3.point3D, triangle.p2.point3D));
        break;
    default:
        throw "Incorrect point number";
        return Vector3();
        break;
    }
}

Vector3 Triangle::calculateVector(Vector3 p1, Vector3 p2)
{
    return Vector3(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z);
}

Vector3 Triangle::crossProduct(Vector3 v1, Vector3 v2)
{
    return Vector3(v1.y * v2.z - v2.y * v1.z, v2.x * v1.z - v1.x * v2.z, v1.x * v2.y - v2.x * v1.y);
}

Triangle::~Triangle()
{
    return;
}
