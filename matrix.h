#ifndef MATRIX_H
#define MATRIX_H

#include "bigpoint.h"
#include <vector>

class Matrix
{
protected:
    int n, m;
    std::vector<std::vector<double>> matrix;

public:
    Matrix();
    Matrix(int n);
    Matrix(int n, int m);

    std::vector<std::vector<double>> getMatrix();
    int getN();
    int getM();

    void set(int i, int j, double value);

    void fillZero();
    Matrix multiply(Matrix m);
    Vector3 multiplyVector(Vector3 p);
    BigPoint myltiplyBigPoint(BigPoint bp);
    void print();

    ~Matrix();
};

#endif // MATRIX_H
