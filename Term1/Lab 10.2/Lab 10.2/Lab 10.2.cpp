#include <iostream>
#include <map>
#include <string>

class NAME {
public:
    std::string first;
    NAME(std::string f) : first(f) {}
    std::string get() const { return first; }

    bool operator<(const NAME& other) const {
        return first < other.first;
    }
};

class NUMBER {
public:
    std::string second;
    NUMBER(std::string s) : second(s) {}
    std::string get() const { return second; }
};

int main() {
    std::map<NAME, NUMBER> phoneBook;

    phoneBook.insert({ NAME("Ivanov"), NUMBER("123-456-789") });
    phoneBook.insert({ NAME("Petrov"), NUMBER("987-654-321") });
    phoneBook.insert({ NAME("Anton"), NUMBER("456-123-789") });
    phoneBook.insert({ NAME("Igor"), NUMBER("654-321-987") });
    phoneBook.insert({ NAME("Bogdan"), NUMBER("321-654-123") });

    printf("Phone book list:\n");
    for (const auto& entry : phoneBook) {
        printf("%s : %s\n", entry.first.get().c_str(), entry.second.get().c_str());
    }

    std::string searchName;
    printf("\nEnter a name to search: ");
    std::cin >> searchName;
    auto searchResult = phoneBook.find(NAME(searchName));
    if (searchResult != phoneBook.end()) {
        printf("Found: %s : %s\n", searchResult->first.get().c_str(), searchResult->second.get().c_str());
    }
    else {
        printf("Not found.\n");
    }

    char startLetter;
    printf("\nEnter the starting letter to filter by: ");
    std::cin >> startLetter;
    printf("Entries starting with %c:\n", startLetter);
    for (const auto& entry : phoneBook) {
        if (entry.first.get()[0] == startLetter) {
            printf("%s : %s\n", entry.first.get().c_str(), entry.second.get().c_str());
        }
    }

    printf("\nEnter the starting letter to delete entries by: ");
    std::cin >> startLetter;
    for (auto it = phoneBook.begin(); it != phoneBook.end();) {
        if (it->first.get()[0] == startLetter) {
            it = phoneBook.erase(it);
        }
        else {
            ++it;
        }
    }

    printf("Updated phone book list:\n");
    for (const auto& entry : phoneBook) {
        printf("%s : %s\n", entry.first.get().c_str(), entry.second.get().c_str());
    }

    return 0;
}