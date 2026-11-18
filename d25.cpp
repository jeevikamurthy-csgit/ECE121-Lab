#include <iostream>
#include <stdexcept>
using namespace std;

class InsufficientFunds : public runtime_error {
public:
    InsufficientFunds() : runtime_error("Insufficient funds for withdrawal") {}
};

class BankAccount {
private:
    double balance;

public:
    explicit BankAccount(double initialBalance) : balance(initialBalance) {}

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFunds();
        }
        balance -= amount;
        cout << "Withdrawal successful. Balance: " << balance << '\n';
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account(500.0);

    try {
        account.withdraw(200.0);
        account.withdraw(400.0);
    } catch (const InsufficientFunds& error) {
        cout << "Error: " << error.what() << '\n';
    }

    return 0;
}
