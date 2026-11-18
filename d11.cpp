#include <iostream>
#include <stdexcept>
using namespace std;

class Fraction {
private:
    long long numerator;
    long long denominator;

    static long long gcd(long long a, long long b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;

        while (b != 0) {
            long long remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }

    void simplify() {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        long long divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }

public:
    Fraction(long long n = 0, long long d = 1)
        : numerator(n), denominator(d) {
        simplify();
    }

    friend istream& operator>>(istream& in, Fraction& fraction) {
        char slash;
        long long n, d;

        if (in >> n >> slash >> d && slash == '/') {
            fraction = Fraction(n, d);
        } else {
            in.setstate(ios::failbit);
        }

        return in;
    }

    friend ostream& operator<<(ostream& out, const Fraction& fraction) {
        out << fraction.numerator << '/' << fraction.denominator;
        return out;
    }
};

int main() {
    Fraction fraction;

    cout << "Enter a fraction (numerator/denominator): ";
    try {
        if (cin >> fraction) {
            cout << "Simplified fraction: " << fraction << '\n';
        } else {
            cout << "Invalid fraction format.\n";
        }
    } catch (const invalid_argument& error) {
        cout << "Error: " << error.what() << '\n';
    }

    return 0;
}
