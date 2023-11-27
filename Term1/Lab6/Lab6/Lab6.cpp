#include <cstdio>
#include <cstdlib>
#include <ctime>

int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    const int matrixSize = 9;
    int matrix[matrixSize][matrixSize];

    for (int i = 0; i < matrixSize; ++i) {
        for (int j = i; j < matrixSize; ++j) {
            matrix[i][j] = generateRandomNumber(0, 9);
            matrix[j][i] = matrix[i][j];
        }
    }

    for (int i = 0; i < matrixSize / 2; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            matrix[matrixSize - 1 - i][j] = matrix[i][j];
        }
    }

    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            if (i == 4) {
                printf("- ");
            }
            else {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}