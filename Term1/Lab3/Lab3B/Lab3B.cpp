/****************************************************/
/*             ����������� ������ N3B               */
/****************************************************/
#include <cstdio>
#include <locale>

#include <cstdio>
#include <locale>

int main() {
    std::locale::global(std::locale(""));

    int n;

    printf("����i�� �i���i��� i�����i�: ");
    scanf_s("%d", &n);

    for (int i = 0; i < n; ++i) {
        int k;

        printf("����i�� �i���i��� ����i�: ");
        scanf_s("%d", &k);

        if (k == 1) {
            printf("� ���� %d ����\n", k);
        }
        else if (k >= 2 && k <= 4) {
            printf("� ���� %d �����\n", k);
        }
        else {
            printf("� ���� %d ����i�\n", k);
        }
    }

    return 0;
}
