#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Team {
protected:
    string name;
    string entityType;
    string project;
    string leader;

public:
    Team(string t = "") : name("Aperture"), project("Portal"), leader("Cave Johnson"), entityType(t) {}

    virtual void displayInformation() = 0;

    static void displayBasicInformation() {
        printf("+---------------------+-----------------------------------+\n");
        printf("|       Field         |             Value                 |\n");
        printf("+---------------------+-----------------------------------+\n");
        printf("| Name                | Aperture                          |\n");
        printf("| Entity type         | system (Employee, Manager, Expert)|\n");
        printf("| Project             | Portal                            |\n");
        printf("| Leader              | Cave Johnson                      |\n");
        printf("+---------------------+-----------------------------------+\n");
    }

    string getEntityType() {
        return entityType;
    }

    void setEntityType(string t) {
        entityType = t;
    }

    virtual void writeToFile(ofstream& file) = 0;
    virtual void readFromFile(ifstream& file) = 0;
};

class Employee : public Team {
private:
    string fullName;
    string position;
    double salary;

public:
    Employee(string name = "", string pos = "", double sal = 0) : Team("Employee"), fullName(name), position(pos), salary(sal) {}

    void setSalary(double sal) {
        salary = sal;
    }

    double getSalary() {
        return salary;
    }

    void displayInformation() override {
        printf("+---------------------+----------------------------------------+\n");
        printf("|       Field         |                 Value                  |\n");
        printf("+---------------------+----------------------------------------+\n");
        printf("| Employee full name  | %-30s         |\n", fullName.c_str());
        printf("| Position            | %-30s         |\n", position.c_str());
        printf("| Salary              | %-30.2f         |\n", salary);
        printf("+---------------------+----------------------------------------+\n");
    }

    void writeToFile(ofstream& file) override {
        file << "Employee\n";
        file << fullName << "\n" << position << "\n" << salary << "\n";
    }

    void readFromFile(ifstream& file) override {
        getline(file, fullName);
        getline(file, position);
        file >> salary;
        file.ignore();
    }
};

class Manager : public Team {
private:
    string fullName;
    string skills;
    string workStatus;

public:
    Manager(string name = "", string sk = "", string status = "") : Team("Manager"), fullName(name), skills(sk), workStatus(status) {}

    string getWorkStatus() {
        return workStatus;
    }

    void displayInformation() override {
        printf("+---------------------+-------------------------------------------------------------+\n");
        printf("|       Field         |                            Value                            |\n");
        printf("+---------------------+-------------------------------------------------------------+\n");
        printf("| Manager full name   | %-30s                              |\n", fullName.c_str());
        printf("| Skills              | %-30s |\n", skills.c_str());
        printf("| Work status         | %-30s                              |\n", workStatus.c_str());
        printf("+---------------------+-------------------------------------------------------------+\n");
    }

    static vector<Manager> findActiveManagers(vector<Manager>& managers) {
        vector<Manager> activeManagers;
        for (auto& manager : managers) {
            if (manager.getWorkStatus() == "active") {
                activeManagers.push_back(manager);
            }
        }
        return activeManagers;
    }

    void replaceManager(string name) {
        fullName = name;
    }

    void writeToFile(ofstream& file) override {
        file << "Manager\n";
        file << fullName << "\n" << skills << "\n" << workStatus << "\n";
    }

    void readFromFile(ifstream& file) override {
        getline(file, fullName);
        getline(file, skills);
        getline(file, workStatus);
    }
};

class Expert : public Team {
private:
    string fullName;
    string specialization;
    string functions;

public:
    Expert(string name = "", string spec = "", string funcs = "") : Team("Expert"), fullName(name), specialization(spec), functions(funcs) {}

    string getSpecialization() {
        return specialization;
    }

    void displayInformation() override {
        printf("+---------------------+--------------------------------------------------------------+\n");
        printf("|       Field         |                             Value                            |\n");
        printf("+---------------------+--------------------------------------------------------------+\n");
        printf("| Expert full name    | %-30s                               |\n", fullName.c_str());
        printf("| Specialization      | %-30s                               |\n", specialization.c_str());
        printf("| Functions           | %-30s |\n", functions.c_str());
        printf("+---------------------+--------------------------------------------------------------+\n");
    }

    void setSpecialization(string spec) {
        specialization = spec;
    }

    static vector<Expert> findExpertsBySpecialization(vector<Expert>& experts, string specialization) {
        vector<Expert> requiredExperts;
        for (auto& expert : experts) {
            if (expert.getSpecialization() == specialization) {
                requiredExperts.push_back(expert);
            }
        }
        return requiredExperts;
    }

    void writeToFile(ofstream& file) override {
        file << "Expert\n";
        file << fullName << "\n" << specialization << "\n" << functions << "\n";
    }

    void readFromFile(ifstream& file) override {
        getline(file, fullName);
        getline(file, specialization);
        getline(file, functions);
    }
};

void writeToFile(vector<Team*> team, string fileName) {
    ofstream file(fileName);
    if (file.is_open()) {
        for (auto& element : team) {
            element->writeToFile(file);
        }
        file.close();
    }
}

void readFromFile(vector<Team*>& team, string fileName) {
    ifstream file(fileName);
    if (file.is_open()) {
        string type;
        while (getline(file, type)) {
            Team* member = nullptr;
            if (type == "Employee") {
                member = new Employee();
            }
            else if (type == "Manager") {
                member = new Manager();
            }
            else if (type == "Expert") {
                member = new Expert();
            }
            if (member) {
                member->readFromFile(file);
                team.push_back(member);
            }
        }
        file.close();
    }
}

void printMainMenu() {
    printf("+-----------------------------------------------------------+\n");
    printf("|                       Choose action                       |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("| 1. Display all information                                |\n");
    printf("| 2. Display information about the team                     |\n");
    printf("| 3. Display information about the employee                 |\n");
    printf("| 4. Display information about the manager                  |\n");
    printf("| 5. Display information about the expert                   |\n");
    printf("| 6. Exit                                                   |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("| Your choice:                                              |\n");
    printf("+-----------------------------------------------------------+\n");
}

void printEmployeeMenu() {
    printf("+-----------------------------------------------------------+\n");
    printf("|                Employee Menu - Choose action              |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("| 1. Get current employee salary                            |\n");
    printf("| 2. Set new employee salary                                |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("| Your choice:                                              |\n");
    printf("+-----------------------------------------------------------+\n");
}

void printManagerMenu() {
    printf("+-----------------------------------------------------------+\n");
    printf("|                 Manager Menu - Choose action              |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("| 1. Find active managers                                   |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("| Your choice:                                              |\n");
    printf("+-----------------------------------------------------------+\n");
}

void printExpertMenu() {
    printf("+-----------------------------------------------------------+\n");
    printf("|                 Expert Menu - Choose action               |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("| 1. Find an expert with the required specialization        |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("| Your choice:                                              |\n");
    printf("+-----------------------------------------------------------+\n");
}

int main() {
    vector<Team*> team;

    Employee employee("Omash Inow Govardenkovich", "operator", 5000);
    Manager manager("Glos Caroline Tomashova", "personnel management, data analysis, customer communication", "absent");
    Expert expert("Atlas Wheatley Sarah", "artificial intelligence", "data analysis, expert evaluation, consultations and training");

    team.push_back(&employee);
    team.push_back(&manager);
    team.push_back(&expert);

    bool continueProgram = true;
    while (continueProgram) {
        printMainMenu();
        int choice;
        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("\n");
            for (auto& member : team) {
                member->displayInformation();
            }
            break;
        case 2:
            printf("\n");
            Team::displayBasicInformation();
            break;
        case 3:
        {
            printf("\n");
            employee.displayInformation();
            printEmployeeMenu();
            int employeeChoice;
            printf("Enter your choice: ");
            scanf_s("%d", &employeeChoice);
            if (employeeChoice == 1) {
                printf("\n");
                printf("+-----------------------------------------------------------+\n");
                printf("| Current employee salary: %.2f$                             \n", employee.getSalary());
                printf("+-----------------------------------------------------------+\n");
            }
            else if (employeeChoice == 2) {
                printf("\n");
                double newSalary;
                printf("+-----------------------------------------------------------+\n");
                printf("| Enter new salary:                                         |\n");
                printf("+-----------------------------------------------------------+\n");
                printf("Your input: ");
                scanf_s("%lf", &newSalary);
                employee.setSalary(newSalary);
                printf("\n");
                printf("+----------------------------------------------------------+\n");
                printf("| New salary set: %.2f$                                     \n", employee.getSalary());
                printf("+----------------------------------------------------------+\n");
            }
            break;
        }
        case 4:
        {
            printf("\n");
            manager.displayInformation();
            printManagerMenu();
            int managerChoice;
            printf("Enter your choice: ");
            scanf_s("%d", &managerChoice);
            if (managerChoice == 1) {
                printf("\n");
                vector<Manager> managers = { manager };
                vector<Manager> activeManagers = Manager::findActiveManagers(managers);
                for (auto& m : activeManagers) {
                    m.displayInformation();
                }
                printf("+-----------------------------------------------------------+\n");
                printf("| Enter new manager from the list (Emily Johnson Smith,     |\n");
                printf("| Alexander Thomson Brown, Olivia Davis Wilson):            |\n");
                printf("+-----------------------------------------------------------+\n");
                string newFullName;
                if (getchar() == EOF) {
                    printf("Error reading input.\n");
                    break;
                }
                getline(cin, newFullName);
                manager.replaceManager(newFullName);
                printf("\n");
                printf("+---------------------------------------------------------------------------------+\n");
                printf("| New manager: %-30s                   \n", newFullName.c_str());
                printf("| The new manager is absent because she(he) is transferred to a new place of work \n");
                printf("+---------------------------------------------------------------------------------+\n");
            }
            break;
        }
        case 5:
        {
            printf("\n");
            expert.displayInformation();
            printExpertMenu();
            int expertChoice;
            printf("Enter your choice: ");
            scanf_s("%d", &expertChoice);
            if (expertChoice == 1) {
                printf("\n");
                vector<Expert> experts = { expert };
                string specialization;
                printf("+-----------------------------------------------------------+\n");
                printf("| Enter specialization (programming, networks, databases):  |\n");
                printf("+-----------------------------------------------------------+\n");
                printf("Your input: ");
                cin >> specialization;
                vector<Expert> requiredExperts = Expert::findExpertsBySpecialization(experts, specialization);
                for (auto& e : requiredExperts) {
                    e.displayInformation();
                }
                printf("+-----------------------------------------------------------+\n");
                printf("| Enter expert's full name:                                 |\n");
                printf("+-----------------------------------------------------------+\n");
                string fullName;
                if (getchar() == EOF) {
                    printf("Error reading input.\n");
                    break;
                }
                getline(cin, fullName);
                expert.setSpecialization(specialization);
                printf("\n");
                printf("+-----------------------------------------------------------------------------------------+\n");
                printf("| New expert found (but not hired): %-20s  \n", fullName.c_str());
                printf("| The head office decided to change the specialization of the current expert: %-30s \n", specialization.c_str());
                printf("+-----------------------------------------------------------------------------------------+\n");

            }
            break;
        }
        case 6:
            continueProgram = false;
            break;
        default:
            printf("\n");
            printf("+-----------------------------------------------------------+\n");
            printf("| Incorrect choice. Please try again.                       |\n");
            printf("+-----------------------------------------------------------+\n");
            break;
        }
    }

    writeToFile(team, "information.txt");

    vector<Team*> newTeam;
    readFromFile(newTeam, "information.txt");

    for (auto& member : newTeam) {
        member->displayInformation();
    }

    for (auto& member : newTeam) {
        delete member;
    }

    return 0;
}