#include <iostream>
#include <string> 

int calculateNegativeProduct(int arr[], int size) {
    int negativeCount = 0; 
    int negativeProduct = 1; 

    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) {
            ++negativeCount;
            negativeProduct *= arr[i]; 
        }
    }

    if (negativeCount >= 2) {
        return negativeProduct;
    }
    else {
        return -1; 
    }
}

int main() {
    std::string continueInput; 

    do {
        int size;
        printf("Enter the size of the array: ");
        if (scanf("%d", &size) != 1 || size <= 0) {
            printf("Invalid array size.\n");
            continue;
        }

        int* arr = new int[size];

        printf("Enter the elements of the array:\n");
        for (int i = 0; i < size; ++i) {
            if (scanf("%d", &arr[i]) != 1) {
                printf("Invalid input for element %d.\n", i + 1);
                delete[] arr;
                return 1;
            }
        }

        int product = calculateNegativeProduct(arr, size);

        if (product != -1) {
            printf("Product of negative elements: %d\n", product);
        }
        else {
            printf("There are not at least two negative elements, please revise.\n");
        }

        delete[] arr; 

        printf("Do you wish to continue? (Yes/No): ");
        std::cin >> continueInput;
    } while (continueInput == "Yes" || continueInput == "yes" || continueInput == "Y" || continueInput == "y");

    return 0;
}