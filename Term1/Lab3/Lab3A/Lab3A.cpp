/****************************************************/
/*             Лабораторна робота N3A               */
/****************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>

int main() {
    double a, b, c;

    printf("a: ");
    if (scanf("%lf", &a) != 1) {
        printf("Invalid input for 'a'.\n");
        return 1;
    }

    printf("b: ");
    if (scanf("%lf", &b) != 1) {
        printf("Invalid input for 'b'.\n");
        return 1;
    }

    printf("c: ");
    if (scanf("%lf", &c) != 1) {
        printf("Invalid input for 'c'.\n");
        return 1;
    }

    double discriminant = b * b - 4 * a * c;

    if (a != 0) {
        printf("The equation is quadratic.\n");

        if (discriminant > 0) {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            printf("Two different mathematical roots: %.2lf and %.2lf\n", root1, root2);
        }
        else if (discriminant == 0) {
            double root = -b / (2 * a);
            printf("One double mathematical root: %.2lf\n", root);
        }
        else {
            printf("The equation has no real mathematical roots.\n");
        }
    }
    else {
        printf("This is not a quadratic equation.\n");
    }

    return 0;
}