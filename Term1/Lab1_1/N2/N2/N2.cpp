#include <iostream>
#include <cmath>

int main() {
    double a, b, c;
    double p, area;

    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;
    std::cout << "c: ";
    std::cin >> c;

    p = (a + b + c) / 2;

    area = sqrt(p * (p - a) * (p - b) * (p - c));

    std::cout << "Sabc: " << area << std::endl;

    return 0;
}

