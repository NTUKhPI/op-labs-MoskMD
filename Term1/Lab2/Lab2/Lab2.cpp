#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip> // ��� ������������� ������
#include "windows.h";
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char name1[9] = "RT-11-24", name2[13] = "RT-11-24", name3[9] = "CGU-12K";
    char sc1 = 'R', sc2 = 'R', sc3 = 'C';
    int cnt1 = 100000, cnt2 = 50000, cnt3 = 17.5;
    float sq1 = 12, sq2 = 10, sq3 = 3;


    printf("|--------------------------------------------|\n");
    printf("|³������ �������������                     |\n");
    printf("|--------------------------------------------|\n");
    printf("| ����������   | ��� | ������  | ʳ������  |\n");
    printf("|--------------|-----|----------|------------|\n");
    printf("| %-12s | %-3c | %-8d | %-11.0f|\n", name1, sc1, cnt1, sq1);
    printf("| %-12s | %-3c | %-8d | %-11.0f|\n", name2, sc2, cnt2, sq2);
    printf("| %-12s | %-3c | %0.1f     | %-11.0f|\n", name3, sc3,17.5, sq3);
    printf("|--------------------------------------------|\n");
    printf("| �������: R � ��������; C � �����������    |\n");
    printf("|--------------------------------------------|\n");
    return 0;
}

