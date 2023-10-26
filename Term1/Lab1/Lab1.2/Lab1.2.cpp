#include <cstdio>
#include <cmath>

int main() {
    double a, b, c;
    double p, area;

    printf("������ a: ");
    if (scanf("%lf", &a) != 1) {
        printf("�������: a �� ���� ������.\n");
        return 1;
    }

    printf("������ b: ");
    if (scanf("%lf", &b) != 1) {
        printf("�������: b �� ���� ������.\n");
        return 1;
    }

    printf("������ c: ");
    if (scanf("%lf", &c) != 1) {
        printf("�������: c �� ���� ������.\n");
        return 1;
    }

    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
        printf("�������: ������ �������� �� ��������� ���������.\n");
        return 1;
    }

    p = (a + b + c) / 2;

    area = sqrt(p * (p - a) * (p - b) * (p - c));

    printf("����� ����������: %lf\n", area);

    return 0;
}
