#include <iostream>
#include <string>
#include <cctype>
#include <locale.h> 

int findWordPosition(const std::string& str, int wordNumber) {
    int rahunok = 0;
    bool u_slovi = false;
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isspace(str[i])) {
            if (!u_slovi) {
                ++rahunok;
                if (rahunok == wordNumber) {
                    return i + 1;
                }
            }
            u_slovi = true;
        }
        else {
            u_slovi = false;
        }
    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8"); 

    while (true) {
        std::string input;
        printf("Enter a string: ");
        std::getline(std::cin, input);

        if (input.empty()) {
            printf("Incorrect input. Please try again.\n");
            continue;
        }

        if (input.length() > 100) {
            printf("String is too long. Please enter a string no longer than 100 characters.\n");
            continue;
        }

        int wordNumber;
        printf("Enter the word number you want to find: ");
        std::cin >> wordNumber;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printf("Incorrect input. Please enter an integer.\n");
            continue;
        }

        int position = findWordPosition(input, wordNumber);
        if (position != -1) {
            printf("Position of word %d in the string: %d\n", wordNumber, position);
        }
        else {
            printf("Word with number %d not found in the string.\n", wordNumber);
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clearing the input buffer
    }

    return 0;
}