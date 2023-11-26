#include <stdio.h>

void findAndReplace(int arr[], int size) {
    int i, j, temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int thirdLargest = arr[2];

    for (i = 0; i < size; i++) {
        if (arr[i] > thirdLargest) {
            arr[i] = thirdLargest;
        }
    }
}

int main(void) {
    int arr[] = { 15, 10, 25, 20, 30, 5, 40, 35, 45, 50, 65, 60, 55, 70, 75, 80, 85, 90, 95, 100 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Initial array:\n");
    for (int i = 0; i < size; i++) {
        printf("%3d ", arr[i]);
    }
    putchar('\n');

    findAndReplace(arr, size);

    printf("Array after replacement:\n");
    for (int i = 0; i < size; i++) {
        printf("%3d ", arr[i]);
    }
    putchar('\n');

    return 0;
}