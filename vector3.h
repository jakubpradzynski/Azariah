#ifndef V3_H
#define V3_H

class Vector3
{
public:

    Vector3();
    Vector3(char* bin);
    Vector3(double x, double y, double z);
    void print();
    ~Vector3();

    double x, y, z;
};

#endif // V3_H
