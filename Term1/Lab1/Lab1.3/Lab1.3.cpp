#include <cstdio>

int main() {
    int base = 2;
    int result = base;

    result = result * result; 
    result = result * result; 
    result = result * result; 

    printf("8th power of a number %d = %d\n", base, result);

    return 0;
}
