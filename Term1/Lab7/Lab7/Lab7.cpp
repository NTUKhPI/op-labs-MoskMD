#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif

int getRandomInt(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        wprintf(L"[");
        for (auto it = row.begin(); it != row.end(); ++it) {
            wprintf(L"%d", *it);
            if (std::next(it) != row.end()) {
                wprintf(L", ");
            }
        }
        wprintf(L"]\n");
    }
}

int main() {
#ifdef _WIN32
    if (_setmode(_fileno(stdout), _O_U16TEXT) == -1) {
        std::cerr << "Error setting console output mode to UTF-8" << std::endl;
        return 1;
    }
#endif

    std::vector<std::vector<int>> matrix(3, std::vector<int>(3));
    for (auto& row : matrix) {
        for (int& value : row) {
            value = getRandomInt(0, 9);
        }
    }

    wprintf(L"ѕочаткова матриц€:\n");
    printMatrix(matrix);
    wprintf(L"\n");

    std::vector<std::vector<int>> mirroredMatrix(3, std::vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        mirroredMatrix[i] = matrix[2 - i];
    }

    wprintf(L"ƒзеркальне в≥дображенн€ по горизонтал≥:\n");
    printMatrix(mirroredMatrix);
    wprintf(L"\n");

    return 0;
}
