#pragma once
#include "IShape.h"
#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Circle : public IShape
{
public:
    Circle(double radius) : radius(radius) {}

    void Draw() override {
        std::cout << "Circle area: " << area << std::endl;
    }

    void Size() override {
        area = M_PI * radius * radius;
    }


    double radius;
    double area;
};
