#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "bigpoint.h"

class Triangle
{
public:
    Triangle();
    Triangle(Vector3 p1, Vector3 p2, Vector3 p3);
    Triangle(Vector3 normal, Vector3 p1, Vector3 p2, Vector3 p3);
    Triangle(BigPoint p1, BigPoint p2, BigPoint p3);
    Triangle(Vector3 normal, BigPoint p1, BigPoint p2, BigPoint p3);
    BigPoint calculateMeanPoint();
    Vector3 calculateNormalVector();
    void print();
    void fillData();
    void fillPointsVectorData();
    double vectorLength(Vector3 vector);
    Vector3 normalizeVector(Vector3 vector);
    Vector3 calculateVectorForPoint(int pointNumber, Triangle triangle);
    Vector3 calculateVector(Vector3 p1, Vector3 p2);
    Vector3 crossProduct(Vector3 v1, Vector3 v2);
    ~Triangle();

    BigPoint p1, p2, p3;
    Vector3 normalVector;
    BigPoint meanPoint;
    double light = 1.;
};

#endif // TRIANGLE_H
