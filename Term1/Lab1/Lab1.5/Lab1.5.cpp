#include <iostream>
int main() {
    int years[] = { 100, 1000, 10000, 100000 };

    for (int i = 0; i < sizeof(years) / sizeof(years[0]); i++) {
        int year = years[i];
        long long seconds = static_cast<long long>(year) * 365 * 24 * 60 * 60;
        printf("In %d years %lld seconds.\n", year, seconds);
    }

    return 0;
}
