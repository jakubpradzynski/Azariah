#include "matrix.h"
#include <iomanip>
#include <iostream>

Matrix::Matrix()
{
    this->n = 1;
    this->m = 1;
    for (int i = 0; i < n; i++) {
        std::vector<double> vector(m);
        matrix.push_back(vector);
    }
}

Matrix::Matrix(int n)
{
    this->n = n;
    this->m = n;
    for (int i = 0; i < n; i++) {
        std::vector<double> vector(m);
        matrix.push_back(vector);
    }
}

Matrix::Matrix(int n, int m)
{
    this->n = n;
    this->m = m;
    for (int i = 0; i < n; i++) {
        std::vector<double> vector(m);
        matrix.push_back(vector);
    }
}

std::vector<std::vector<double> > Matrix::getMatrix()
{
    return this->matrix;
}

int Matrix::getN()
{
    return this->n;
}

int Matrix::getM()
{
    return this->m;
}

void Matrix::set(int i, int j, double value)
{
    this->matrix.at(i).at(j) = value;
}

void Matrix::fillZero()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            matrix.at(i).at(j) = 0.0;
        }
    }
}

Matrix Matrix::multiply(Matrix m)
{
    if (this->getM() != m.getN()) throw "Not correct matrixs for multiply";
    Matrix C = Matrix(this->getN(), m.getM());
    for(int i = 0; i < this->getN(); i++)
    {
        for(int j = 0; j < m.getM(); j++)
        {
            double s = 0.0;

            for(int k = 0; k < this->getM(); k++) {
                s += this->getMatrix()[i][k] * m.getMatrix()[k][j];
            }
            C.set(i, j, s);
        }
    }
    return C;
}

Vector3 Matrix::multiplyVector(Vector3 p)
{
    Vector3 point = Vector3();
    Matrix vector = Matrix(4, 1);
    vector.set(0., 0., (double)p.x);
    vector.set(1., 0., (double)p.y);
    vector.set(2., 0., (double)p.z);
    vector.set(3., 0., (double)1);
    vector = this->multiply(vector);
    point.x = ((double)vector.getMatrix()[0][0]);
    point.y = ((double)vector.getMatrix()[1][0]);
    point.z = ((double)vector.getMatrix()[2][0]);
    return point;
}

BigPoint Matrix::myltiplyBigPoint(BigPoint bp)
{
    BigPoint newBP = bp;
    Matrix vector = Matrix(4, 1);
    vector.set(0., 0., bp.point3D.x);
    vector.set(1., 0., bp.point3D.y);
    vector.set(2., 0., bp.point3D.z);
    vector.set(3., 0., 1.);
    vector = this->multiply(vector);
    newBP.point3DAfterTransform.x = (vector.getMatrix()[0][0]);
    newBP.point3DAfterTransform.y = (vector.getMatrix()[1][0]);
    newBP.point3DAfterTransform.z = (vector.getMatrix()[2][0]);
    return newBP;
}

void Matrix::print()
{
    for(int i = 0; i < this->getN(); i++)
    {
        for(int j = 0; j < this->getM(); j++) std::cout << std::setw(6) << this->matrix[i][j];
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

Matrix::~Matrix()
{

}
