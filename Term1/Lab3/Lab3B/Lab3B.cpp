/****************************************************/
/*             Лабораторна робота N3B               */
/****************************************************/
#include <iostream>
#include <locale>

int main() {
    std::locale::global(std::locale(""));

    int n;

    std::wcout << L"Введiть кiлькiсть iтерацiй: ";
    std::wcin >> n;

    for (int i = 0; i < n; ++i) {
        int k;

        std::wcout << L"Введiть кiлькiсть грибiв: ";
        std::wcin >> k;

        if (k == 1) {
            std::wcout << L"У мене " << k << L" гриб" << std::endl;
        }
        else if (k >= 2 && k <= 4) {
            std::wcout << L"У мене " << k << L" гриби" << std::endl;
        }
        else {
            std::wcout << L"У мене " << k << L" грибiв" << std::endl;
        }
    }

    return 0;
}