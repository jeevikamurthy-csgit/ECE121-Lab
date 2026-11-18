#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;

public:
    Employee(const string& employeeName, int employeeId)
        : name(employeeName), id(employeeId) {}

    virtual void printDetails() const {
        cout << "Name: " << name << "\nID: " << id << '\n';
    }

    virtual ~Employee() = default;
};

class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(const string& name, int id, int size)
        : Employee(name, id), teamSize(size) {}

    void printDetails() const override {
        cout << "Manager\n";
        Employee::printDetails();
        cout << "Team size: " << teamSize << '\n';
    }
};

class Engineer : public Employee {
private:
    string skill;

public:
    Engineer(const string& name, int id, const string& skillName)
        : Employee(name, id), skill(skillName) {}

    void printDetails() const override {
        cout << "Engineer\n";
        Employee::printDetails();
        cout << "Skill: " << skill << '\n';
    }
};

int main() {
    Manager manager("Asha", 101, 8);
    Engineer engineer("Ravi", 102, "C++");

    manager.printDetails();
    cout << '\n';
    engineer.printDetails();

    return 0;
}
