#include <iostream>
#include <stdexcept>
#include <cstring>

template <typename T>
class Number {
private:
    T value;

public:
    Number() : value(0) {}
    Number(T val) : value(val) {}

    void print() const {
        printf("Value: %f\n", static_cast<double>(value)); 
    }

    Number operator+(const Number& other) const {
        return Number(value + other.value);
    }
};

int main() {
    try {
        while (true) {

            int intValue = 0;
            double doubleValue = 0.0;

            printf("Enter an integer: ");
            scanf_s("%d", &intValue);

            printf("Enter a double: ");
            scanf_s("%lf", &doubleValue);

            Number<int> intNum(intValue);
            Number<double> doubleNum(doubleValue);

            printf("Integer: ");
            intNum.print();

            printf("Double: ");
            doubleNum.print();

            Number<int> sumInt = intNum + intNum;
            printf("Sum of integers: ");
            sumInt.print();

            Number<double> sumDouble = doubleNum + doubleNum;
            printf("Sum of doubles: ");
            sumDouble.print();

            printf("Continue? (yes/no): ");
            char choice[10] = { 0 }; 
            scanf_s("%s", choice, 10);
            if (strcmp(choice, "yes") != 0) {
                break;
            }
        }
    }
    catch (const std::exception& e) {
        fprintf(stderr, "Exception caught: %s\n", e.what());
    }

    return 0;
}