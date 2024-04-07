#include <iostream>
#include <string>
#include <sstream>

void calculateTimeIndex(int seconds, int* hours, int* minutes) {
    *hours = seconds / 3600; 
    seconds %= 3600;
    *minutes = seconds / 60; 
}

void calculateTimeLink(int seconds, int& hours, int& minutes) {
    hours = seconds / 3600;
    seconds %= 3600;
    minutes = seconds / 60;
}

bool isNumeric(const std::string& input) {
    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string continueLoop;
    do {
        std::string input;
        int totalSeconds;

        while (true) {
            printf("Enter the total number of seconds: ");
            std::cin >> input;

            if (isNumeric(input)) {
                std::istringstream(input) >> totalSeconds;
                break;
            }
            else {
                printf("Error: Please enter a valid number.\n");
                printf("Do you want to continue? (Yes | No): ");
                std::cin >> continueLoop;
                if (continueLoop != "Yes" && continueLoop != "yes") {
                    return 0;
                }
            }
        }

        int hoursIndex, minutesIndex;
        int hoursLink, minutesLink;

        calculateTimeIndex(totalSeconds, &hoursIndex, &minutesIndex);
        calculateTimeLink(totalSeconds, hoursLink, minutesLink);

        printf("Using index: %d hours %d minutes\n", hoursIndex, minutesIndex);
        printf("Using link: %d hours %d minutes\n", hoursLink, minutesLink);

        printf("Do you want to continue? (Yes | No): ");
        std::cin >> continueLoop;
    } while (continueLoop == "Yes" || continueLoop == "yes");

    return 0;
}