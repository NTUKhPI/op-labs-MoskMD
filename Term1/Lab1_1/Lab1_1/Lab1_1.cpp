#include <iostream>
int main() 
{
    int intSize = sizeof(int);
    int shortSize = sizeof(short);
    int longSize = sizeof(long);
    int charSize = sizeof(char);
    int floatSize = sizeof(float);
    int doubleSize = sizeof(double);

    double a, b, c;
    a = 5.0;
    b = 6.0;
    c = 7.0;
    double p = (a + b + c) / 2; 
    double area = sqrt(p * (p - a) * (p - b) * (p - c)); 

    int num = 5;
    num = (num << 3); 

    int x = 5;
    int y = 10;
    int temp = x;
    x = y;
    y = temp;

    int m = 15;
    int n = 20;
    m = m + n;
    n = m - n;
    m = m - n;

    long long years = 100000;
    long long daysInYear = 365; 
    long long seconds = years * daysInYear * 24 * 3600;

    std::cout << "Sizes in bytes: int=" << intSize << ", short=" << shortSize << ", long=" << longSize
        << ", char=" << charSize << ", float=" << floatSize << ", double=" << doubleSize << std::endl;
    std::cout << "Triangle area: " << area << std::endl;
    std::cout << "8th power of 5: " << num << std::endl;
    std::cout << "Swapped values (with temp): x=" << x << ", y=" << y << std::endl;
    std::cout << "Swapped values (without temp): m=" << m << ", n=" << n << std::endl;
    std::cout << "Seconds in " << years << " years: " << seconds << std::endl;

    return 0;
}