/****************************************************/
/*             Лабораторна робота N3B               */
/****************************************************/
#include <cstdio>

int main() {
    int k;

    printf("Enter the number of mushrooms: ");
    if (scanf_s("%d", &k) != 1) {
        printf("Input error\n");
        return 1;
    }

    printf_s("I have %d mushroom%s\n", k, (k != 1) ? "s" : "");

    return 0;
}
