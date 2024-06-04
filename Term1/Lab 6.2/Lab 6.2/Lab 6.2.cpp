#include <iostream>
#include <string>

using namespace std;

struct Component {
    string code;
    char type;
    float nominal;
    int quantity;

    Component() : code(""), type(' '), nominal(0.0f), quantity(0) {}
};

class ComponentRecord {
private:
    Component component;

public:

    ComponentRecord() : component() {}

    ComponentRecord(string code, char type, float nominal, int quantity) {
        component.code = code;
        component.type = type;
        component.nominal = nominal;
        component.quantity = quantity;
    }

    ComponentRecord(const ComponentRecord& other) {
        component = other.component;
    }

    string getCode() {
        return component.code;
    }

    char getType() {
        return component.type;
    }

    float getNominal() {
        return component.nominal;
    }

    int getQuantity() {
        return component.quantity;
    }

    void setCode(string code) {
        component.code = code;
    }

    void setType(char type) {
        component.type = type;
    }

    void setNominal(float nominal) {
        component.nominal = nominal;
    }

    void setQuantity(int quantity) {
        component.quantity = quantity;
    }

    void show() {
        printf("Code: %s\n", component.code.c_str());
        printf("Type: %c\n", component.type);
        printf("Nominal: %.2f\n", component.nominal);
        printf("Quantity: %d\n", component.quantity);
    }

    bool operator==(const ComponentRecord& other) {
        return (component.code == other.component.code &&
            component.type == other.component.type &&
            component.nominal == other.component.nominal &&
            component.quantity == other.component.quantity);
    }

    ComponentRecord& operator=(const ComponentRecord& other) {
        if (this != &other) {
            component = other.component;
        }
        return *this;
    }

    ComponentRecord operator+(const ComponentRecord& other) {
        ComponentRecord result;
        result.component.nominal = component.nominal + other.component.nominal;
        result.component.quantity = component.quantity + other.component.quantity;
        return result;
    }

    friend bool operator==(const ComponentRecord& cr1, const ComponentRecord& cr2);
    friend ComponentRecord operator+(const ComponentRecord& cr1, const ComponentRecord& cr2);

    int operator[](int index) {
        return component.code.length(); 
    }

    void operator()(string code, char type, float nominal, int quantity) {
        component.code = code;
        component.type = type;
        component.nominal = nominal;
        component.quantity = quantity;
    }

    friend ostream& operator<<(ostream& os, const ComponentRecord& cr);
    friend istream& operator>>(istream& is, ComponentRecord& cr);
};

bool operator==(const ComponentRecord& cr1, const ComponentRecord& cr2) {
    return (cr1.component.code == cr2.component.code &&
        cr1.component.type == cr2.component.type &&
        cr1.component.nominal == cr2.component.nominal &&
        cr1.component.quantity == cr2.component.quantity);
}

ComponentRecord operator+(const ComponentRecord& cr1, const ComponentRecord& cr2) {
    ComponentRecord result;
    result.component.nominal = cr1.component.nominal + cr2.component.nominal;
    result.component.quantity = cr1.component.quantity + cr2.component.quantity;
    return result;
}

ostream& operator<<(ostream& os, const ComponentRecord& cr) {
    os << "Code: " << cr.component.code << endl;
    os << "Type: " << cr.component.type << endl;
    os << "Nominal: " << cr.component.nominal << endl;
    os << "Quantity: " << cr.component.quantity << endl;
    return os;
}

istream& operator>>(istream& is, ComponentRecord& cr) {
    printf("Enter code: ");
    is >> cr.component.code;
    printf("Enter type: ");
    is >> cr.component.type;
    printf("Enter nominal: ");
    is >> cr.component.nominal;
    printf("Enter quantity: ");
    is >> cr.component.quantity;
    return is;
}

int main() {
    ComponentRecord component1("RT-11-24", 'R', 100000, 12);
    ComponentRecord component2("RT-11-24", 'R', 50000, 10);
    ComponentRecord component3("CGU-12K", 'C', 17.5, 3);

    while (true) {
        printf("\nMENU:\n");
        printf("1. Show information about Component 1\n");
        printf("2. Show information about Component 2\n");
        printf("3. Show information about Component 3\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            printf("\nComponent 1 information:\n");
            component1.show();
            break;
        case 2:
            printf("\nComponent 2 information:\n");
            component2.show();
            break;
        case 3:
            printf("\nComponent 3 information:\n");
            component3.show();
            break;
        case 4:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice! Please enter a number between 1 and 4.\n");
            break;
        }
    }

    return 0;
}