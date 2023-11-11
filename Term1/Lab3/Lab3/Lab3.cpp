/****************************************************/
/*             Лабораторна робота N3                */
/*               Умовний оператор                   */
/*                  Варіант N7                      */
/****************************************************/

#include <stdio.h>

int main() {
    double x, y;

    printf("Enter the coordinate x >");
    scanf_s("%lf", &x);
    printf("Enter the coordinate y >");
    scanf_s("%lf", &y);

    printf("x=%6.3lf; y=%6.3lf\n", x, y);

    if ((x == -1 && y >= -1 && y < 0) ||  
        (y == -1 && x >= -1 && x < 0) || 
        (x == 0 && y >= 0 && x * x + y * y <= 1) ||  
        (y == 0 && x >= 0 && x * x + y * y <= 1))    
    {
        printf("The point falls into the given area\n");
    }

    else if (
        (x > -1 && x < 0 && y > -1 && y < 0) ||  
        (x >= 0 && y >= 0 && x * x + y * y <= 1) 
        )
    {
        printf("The point falls into the given area\n");
    }
    else {
        printf("The point does not fall into the specified area\n");
    }

    return 0;
}