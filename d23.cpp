#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Logger {
public:
    virtual void write(const string& message) = 0;
    virtual ~Logger() = default;
};

class ConsoleLogger : public Logger {
public:
    void write(const string& message) override {
        cout << "Console: " << message << '\n';
    }
};

class FileLogger : public Logger {
private:
    ofstream file;

public:
    FileLogger() : file("log.txt") {
        if (!file) {
            throw runtime_error("Could not open log.txt");
        }
    }

    void write(const string& message) override {
        file << message << '\n';
    }
};

int main() {
    int choice;
    cout << "Choose logger (1 = console, 2 = file): ";
    cin >> choice;

    try {
        ConsoleLogger consoleLogger;
        FileLogger fileLogger;
        Logger* logger = nullptr;

        if (choice == 1) {
            logger = &consoleLogger;
        } else if (choice == 2) {
            logger = &fileLogger;
        } else {
            cout << "Invalid choice\n";
            return 1;
        }

        logger->write("Application started");
    } catch (const exception& error) {
        cerr << "Error: " << error.what() << '\n';
        return 1;
    }

    return 0;
}
