#include <iostream>
#include "Min.h" // ヘッダファイルをインクルード

int main() {
    Min<int, int> intToInt(10, 20);
    std::cout << "Min(int, int): " << intToInt.GetMin() << std::endl;

    Min<int, float> intToFloat(10, 20.0f);
    std::cout << "Min(int, float): " << intToFloat.GetMin() << std::endl;

    Min<int, double> intToDouble(10, 20.0);
    std::cout << "Min(int, double): " << intToDouble.GetMin() << std::endl;

    Min<float, float> floatToFloat(10.0f, 20.0f);
    std::cout << "Min(float, float): " << floatToFloat.GetMin() << std::endl;

    Min<float, double> floatToDouble(10.0f, 20.0);
    std::cout << "Min(float, double): " << floatToDouble.GetMin() << std::endl;

    Min<double, double> doubleToDouble(10.0, 20.0);
    std::cout << "Min(double, double): " << doubleToDouble.GetMin() << std::endl;

    return 0;
}
