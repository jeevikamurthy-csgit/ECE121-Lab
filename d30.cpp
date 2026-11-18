#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Student {
public:
    string name;
    double marks;

    Student(const string& studentName, double studentMarks)
        : name(studentName), marks(studentMarks) {}
};

int main() {
    ifstream input("students.txt");

    if (!input) {
        cerr << "Could not open students.txt\n";
        return 1;
    }

    vector<Student> students;
    string name;
    double marks;

    while (input >> name >> marks) {
        students.emplace_back(name, marks);
    }

    if (students.empty()) {
        cout << "No student records found\n";
        return 0;
    }

    int topperIndex = 0;

    for (int i = 1; i < static_cast<int>(students.size()); ++i) {
        if (students[i].marks > students[topperIndex].marks) {
            topperIndex = i;
        }
    }

    cout << "Topper: " << students[topperIndex].name << '\n'
         << "Marks: " << students[topperIndex].marks << '\n';

    return 0;
}
