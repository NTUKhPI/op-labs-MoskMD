#include <iostream>

int main() {
    int base = 2; 
    int result = base; 

    result = result * result; // ����� �������� (� �������)
    result = result * result; // ����� �������� (� �������� ������)
    result = result * result; // ���� �������� (� ������ ������)

    std::cout << "8th power of a number " << base << " = " << result << std::endl;

    return 0;
}
