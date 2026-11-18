#include <iostream>
#include <stdexcept>
using namespace std;

class MathError : public runtime_error {
public:
    MathError() : runtime_error("A math error occurred") {}
};

class DivideByZero : public MathError {
public:
    DivideByZero() : MathError() {}
};

void divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw DivideByZero();
    }
    cout << "Result: " << numerator / denominator << '\n';
}

int main() {
    cout << "Incorrect catch order:\n";
    try {
        divide(10, 0);
    } catch (const MathError& error) { // Catches DivideByZero too
        cout << "Caught by MathError: " << error.what() << '\n';
    } catch (const DivideByZero& error) {
        // This handler is unreachable for DivideByZero in this order.
        cout << "Caught by DivideByZero: " << error.what() << '\n';
    }

    cout << "\nCorrect catch order:\n";
    try {
        divide(10, 0);
    } catch (const DivideByZero& error) { // Specific type first
        cout << "Caught by DivideByZero: " << error.what() << '\n';
    } catch (const MathError& error) {
        cout << "Caught by MathError: " << error.what() << '\n';
    }

    return 0;
}
