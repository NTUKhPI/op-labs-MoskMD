#include <iostream>

int main() {
    int base = 2; 
    int result = base; 

    result = result * result; // Перше множення (в квадрат)
    result = result * result; // Друге множення (в четверту ступінь)
    result = result * result; // Третє множення (в восьму ступінь)

    std::cout << "8th power of a number " << base << " = " << result << std::endl;

    return 0;
}
