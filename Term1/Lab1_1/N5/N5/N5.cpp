#include <iostream>
#include <cstdint> 

int main() {
    int64_t years = 100; 

    int64_t secondsInDay = 24 * 60 * 60;
    int64_t daysInYear = 365;

    int64_t totalSeconds = years * daysInYear * secondsInDay;

    std::cout << "Number of seconds in " << years << " years: " << totalSeconds << std::endl;

    return 0;
}

