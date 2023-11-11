/****************************************************/
/*             Лабораторна робота N3B               */
/****************************************************/
#include <cstdio>
#include <locale>

#include <cstdio>
#include <locale>

int main() {
    std::locale::global(std::locale(""));

    int n;

    printf("Введiть кiлькiсть iтерацiй: ");
    scanf_s("%d", &n);

    for (int i = 0; i < n; ++i) {
        int k;

        printf("Введiть кiлькiсть грибiв: ");
        scanf_s("%d", &k);

        if (k == 1) {
            printf("У мене %d гриб\n", k);
        }
        else if (k >= 2 && k <= 4) {
            printf("У мене %d гриби\n", k);
        }
        else {
            printf("У мене %d грибiв\n", k);
        }
    }

    return 0;
}
