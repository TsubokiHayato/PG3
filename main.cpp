#include <iostream>
#include "Circle.h"
#include "Rectangle.h"

int main() {
    // Circleの例
    Circle circle(5.0); // 半径5の円
    circle.Size();
    circle.Draw(); // 面積を表示

    // Rectangleの例
    Rectangle rectangle(4.0, 6.0); // 幅4、高さ6の長方形
    rectangle.Size();
    rectangle.Draw(); // 面積を表示

    return 0;
}
