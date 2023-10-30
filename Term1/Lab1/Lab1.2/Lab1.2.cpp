#include <cstdio>
#include <cmath>

int main() {
    double a, b, c;
    double p, area;

    printf("Введіть a: ");
    if (scanf("%lf", &a) != 1) {
        printf("Помилка: a має бути числом.\n");
        return 1;
    }

    printf("Введіть b: ");
    if (scanf("%lf", &b) != 1) {
        printf("Помилка: b має бути числом.\n");
        return 1;
    }

    printf("Введіть c: ");
    if (scanf("%lf", &c) != 1) {
        printf("Помилка: c має бути числом.\n");
        return 1;
    }

    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
        printf("Помилка: введені значення не утворюють трикутник.\n");
        return 1;
    }

    p = (a + b + c) / 2;

    area = sqrt(p * (p - a) * (p - b) * (p - c));

    printf("Площа трикутника: %lf\n", area);

    return 0;
}
