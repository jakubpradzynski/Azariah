#ifndef RGB_H
#define RGB_H

class RGB
{
public:
    RGB();
    RGB(int r, int g, int b);
    RGB(double r, double g, double b);
    void print();
    ~RGB();

    int r, g, b;
};

#endif // RGB_H
