/****************************************************/
/*             ����������� ������ N3B               */
/****************************************************/
#include <iostream>
#include <locale>

int main() {
    std::locale::global(std::locale(""));

    int n;

    std::wcout << L"����i�� �i���i��� i�����i�: ";
    std::wcin >> n;

    for (int i = 0; i < n; ++i) {
        int k;

        std::wcout << L"����i�� �i���i��� ����i�: ";
        std::wcin >> k;

        if (k == 1) {
            std::wcout << L"� ���� " << k << L" ����" << std::endl;
        }
        else if (k >= 2 && k <= 4) {
            std::wcout << L"� ���� " << k << L" �����" << std::endl;
        }
        else {
            std::wcout << L"� ���� " << k << L" ����i�" << std::endl;
        }
    }

    return 0;
}