#include <iostream>
#include <locale>

void fillArray(int* arr, int size) {
    std::wprintf(L"Enter %d integers:\n", size);
    for (int i = 0; i < size; ++i) {
        if (wscanf_s(L"%d%*c", arr + i) != 1) {
            fwprintf(stderr, L"Input error. Please enter an integer.\n");
            exit(EXIT_FAILURE);
        }
    }
}

void processArray(int* arr, int size) {
    if (size < 6) {
        fwprintf(stderr, L"The size of the array is too small.\n");
        return;
    }

    int* startPtr = arr + 2;
    int* endPtr = arr + size - 3;

    int count = static_cast<int>(endPtr - startPtr) + 1;

    int* secondArray = new int[count];
    for (int i = 0; i < count; ++i) {
        *(secondArray + i) = *(startPtr + i);
    }

    int sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += *(startPtr + i);
    }
    wprintf(L"The sum of elements between the third from the beginning and third from the end: %d\n", sum);

    wprintf(L"Elements between the third from the beginning and third from the end in the second array:\n");
    for (int i = 0; i < count; ++i) {
        wprintf(L"%d ", *(secondArray + i));
    }
    wprintf(L"\n");

    delete[] secondArray;
}

int main() {
    int N;

    if (!setlocale(LC_ALL, "en_US.utf8")) {
        fwprintf(stderr, L"Failed to set the locale for English language.\n");
        return EXIT_FAILURE;
    }

    wprintf(L"Enter the size of the array: ");
    if (wscanf_s(L"%d", &N) != 1) {
        fwprintf(stderr, L"Input error for the array size. Please enter an integer.\n");
        return EXIT_FAILURE;
    }

    int* array = new int[N];

    fillArray(array, N);

    processArray(array, N);

    delete[] array;

    return 0;
}