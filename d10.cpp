#include <iostream>
#include <iomanip>
using namespace std;

class Money {
private:
    long long totalPaise;

public:
    Money(long long rupees = 0, long long paise = 0)
        : totalPaise(rupees * 100 + paise) {}

    Money operator+(const Money& other) const {
        return Money(0, totalPaise + other.totalPaise);
    }

    Money operator-(const Money& other) const {
        return Money(0, totalPaise - other.totalPaise);
    }

    friend ostream& operator<<(ostream& out, const Money& money) {
        long long absolutePaise =
            (money.totalPaise < 0) ? -money.totalPaise : money.totalPaise;

        if (money.totalPaise < 0) {
            out << '-';
        }

        out << "Rs. " << absolutePaise / 100
            << '.' << setw(2) << setfill('0') << absolutePaise % 100
            << setfill(' ');

        return out;
    }
};

int main() {
    Money first(12, 75);
    Money second(5, 50);

    cout << "First amount: " << first << '\n';
    cout << "Second amount: " << second << '\n';
    cout << "Sum: " << first + second << '\n';
    cout << "Difference: " << first - second << '\n';

    return 0;
}
