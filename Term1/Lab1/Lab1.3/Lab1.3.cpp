#include <iostream>
using namespace std;

int main() {
    double x = 2; // Число

    double x_to_4 = x * x * x * x;

    double x_to_8 = x_to_4 * x_to_4;

    printf("x^8: %lf\n", x_to_8);

    return 0;
}
