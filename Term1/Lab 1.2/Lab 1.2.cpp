#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, S, p;

    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);
    printf("c: ");
    scanf("%f", &c);

    p = (a + b + c) / 2;
    S = sqrt(p * (p - a) * (p - b) * (p - c));

    printf(" The area of the triangle is : %.2f\n", S);

    return 0;
}
