#include <cstdio>
#include <cstdlib>

class Base {
public:
    virtual void show() {
        printf("Base\n");
    }
};

class B1 : public Base {
public:
    void show() override {
        printf("B1(public)\n");
        printf(" |\n");
        printf("D1(public)\n");
        printf(" |\n");
        printf("D2\n");
    }
};

class B2 : public Base {
public:
    void show() override {
        printf("B2(public)\n");
        printf(" |\n");
        printf("D1(public)\n");
        printf(" |\n");
        printf("D2\n");
    }
};

class B3 : public Base {
public:
    void show() override {
        printf("B3(public)\n");
        printf(" |\n");
        printf("D1(public)\n");
        printf(" |\n");
        printf("D2\n");
    }
};

class D1 : public Base {
public:
    void show() override {
        printf("D1(public)\n");
        printf(" |\n");
        printf("D2\n");
    }
};

class D2 : public Base {
};

int main() {
    char input[10];
    int choice;
    while (true) {
        printf("Menu\n");
        printf("1. B1(public)\n");
        printf("2. B2(public)\n");
        printf("3. B3(public)\n");
        printf("4. B1(public) - B2(public) - B3(public)\n");
        printf("5. B1(public) - B2(public)\n");
        printf("6. B2(public) - B3(public)\n");
        printf("7. B1(public) - B3(public)\n");
        printf("8. D1(public)\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        fgets(input, sizeof(input), stdin);
        choice = atoi(input);

        Base* obj;

        switch (choice) {
        case 1:
            obj = new B1();
            obj->show();
            delete obj;
            break;
        case 2:
            obj = new B2();
            obj->show();
            delete obj;
            break;
        case 3:
            obj = new B3();
            obj->show();
            delete obj;
            break;
        case 4:
            printf("B1(public)  B2(public)  B3(public)\n");
            printf("             |\n");
            printf("            D1(public)\n");
            printf("             |\n");
            printf("            D2\n");
            break;
        case 5:
            printf("B1(public)  B2(public)\n");
            printf("             |\n");
            printf("            D1(public)\n");
            printf("             |\n");
            printf("            D2\n");
            break;
        case 6:
            printf("B2(public)  B3(public)\n");
            printf("             |\n");
            printf("            D1(public)\n");
            printf("             |\n");
            printf("            D2\n");
            break;
        case 7:
            printf("B1(public)  B3(public)\n");
            printf("             |\n");
            printf("            D1(public)\n");
            printf("             |\n");
            printf("            D2\n");
            break;
        case 8:
            obj = new D1();
            obj->show();
            delete obj;
            break;
        case 9:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice\n");
        }
        printf("\n");
    }

    return 0;
}