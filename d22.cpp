#include <iostream>
using namespace std;

class Account {
protected:
    double balance;

public:
    explicit Account(double amount) : balance(amount) {}

    virtual double calculateInterest() const = 0;

    virtual ~Account() = default;
};

class Savings : public Account {
public:
    explicit Savings(double amount) : Account(amount) {}

    double calculateInterest() const override {
        return balance * 0.04; // 4% interest
    }
};

class Current : public Account {
public:
    explicit Current(double amount) : Account(amount) {}

    double calculateInterest() const override {
        return balance * 0.02; // 2% interest
    }
};

int main() {
    Savings savings(10000);
    Current current(20000);

    Account* accounts[] = {&savings, &current};

    for (Account* account : accounts) {
        cout << "Interest: " << account->calculateInterest() << '\n';
    }

    return 0;
}
