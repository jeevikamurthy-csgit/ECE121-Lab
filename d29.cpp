#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream input("in.txt");
    ofstream output("out.txt");

    if (!input) {
        cerr << "Could not open in.txt\n";
        return 1;
    }

    if (!output) {
        cerr << "Could not create out.txt\n";
        return 1;
    }

    string line;
    int lineNumber = 1;

    while (getline(input, line)) {
        output << lineNumber << ": " << line << '\n';
        ++lineNumber;
    }

    cout << "Numbered copy written to out.txt\n";
    return 0;
}
