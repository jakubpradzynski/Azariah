#ifndef OBJECT3D_H
#define OBJECT3D_H

#include <vector>
#include "triangle.h"

class Object3D
{
public:
    Object3D();
    Object3D(std::vector<Triangle> t);
    void print();
    void fillTrianglesData();
    void fillMeanPointsData();
    void initBufferZ(double value);
    void fillColorInPoints(RGB color);
    ~Object3D();

    std::vector<Triangle> triangles;
    bool sceletonOption, paintedOption, hideBackSurfaces, smoothingOption;
    double bufferZ[1100][880];
};

#endif // OBJECT3D_H
