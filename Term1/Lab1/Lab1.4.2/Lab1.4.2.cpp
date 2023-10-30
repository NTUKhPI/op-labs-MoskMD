#include <iostream>

int main() {
    int a = 5;
    int b = 10;

    a = a + b;
    b = a - b;
    a = a - b;

    printf("a = %d, b = %d\n", a, b);

    return 0;
}
