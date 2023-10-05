#include <iostream>

int main() {
    int a = 5;
    int b = 10;

    int temp = a;
    a = b;
    b = temp;

    std::cout << "a = " << a << ", b = " << b << std::endl;

    return 0;
}
