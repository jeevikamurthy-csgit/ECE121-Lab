#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    explicit Person(const string& personName) : name(personName) {}

    void printPerson() const {
        cout << "Name: " << name << '\n';
    }
};

class Student : virtual public Person {
protected:
    int studentId;

public:
    Student(const string& personName, int id)
        : Person(personName), studentId(id) {}
};

class Employee : virtual public Person {
protected:
    int employeeId;

public:
    Employee(const string& personName, int id)
        : Person(personName), employeeId(id) {}
};

class TA : public Student, public Employee {
private:
    string course;

public:
    TA(const string& personName, int studentId, int employeeId,
       const string& courseName)
        : Person(personName),  // TA initializes the shared virtual base
          Student(personName, studentId),
          Employee(personName, employeeId),
          course(courseName) {}

    void printDetails() const {
        printPerson();
        cout << "Student ID: " << studentId << '\n'
             << "Employee ID: " << employeeId << '\n'
             << "Course: " << course << '\n';
    }
};

int main() {
    TA assistant("Maya", 2025, 501, "Programming");

    assistant.printDetails();
    return 0;
}
