#include "object3d.h"
#include <iostream>

Object3D::Object3D()
{
    sceletonOption = true;
    hideBackSurfaces = false;
    paintedOption = false;
    smoothingOption = false;
}

Object3D::Object3D(std::vector<Triangle> t)
{
    this->triangles = t;
    sceletonOption = true;
    hideBackSurfaces = false;
    paintedOption = false;
    smoothingOption = false;
}

void Object3D::print()
{
    std::cout << "Object3D :" << std::endl;
    for (int i = 0; i < triangles.size(); i++) {
        triangles.at(i).print();
    }
}

void Object3D::fillTrianglesData()
{
    for (int i = 0; i < triangles.size(); i++) {
        triangles.at(i).fillData();
    }
}

void Object3D::fillMeanPointsData()
{
    for (int i = 0; i < triangles.size(); i++) {
        triangles.at(i).meanPoint = triangles.at(i).calculateMeanPoint();
    }
}

void Object3D::initBufferZ(double value)
{
    for (int i = 0; i < 1100; i++) {
        for (int j = 0; j < 880; j++) {
            bufferZ[i][j] = value;
        }
    }
}

void Object3D::fillColorInPoints(RGB color)
{
    for (int i = 0; i < triangles.size(); i++) {
        triangles.at(i).fillColorInPoints(color);
    }
}

Object3D::~Object3D()
{
    return;
}
