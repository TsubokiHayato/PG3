#pragma once
#include "IShape.h"
#include <iostream>

class Rectangle : public IShape
{
public:
    Rectangle(double width, double height) : width(width), height(height) {}

    void Draw() override {
        std::cout << "Rectangle area: " << area << std::endl;
    }

    void Size() override {
        area = width * height;
    }


    double width;
    double height;
    double area;
};
