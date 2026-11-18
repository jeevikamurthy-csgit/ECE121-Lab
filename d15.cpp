
#include <iostream>
using namespace std;

// Minimum of two numbers
inline int minVal(int a, int b) {
    return (a < b) ? a : b;
}

// Minimum of three numbers
inline int minVal(int a, int b, int c) {
    return minVal(minVal(a, b), c);
}

int main() {
    cout << "Minimum of two numbers: " << minVal(10, 5) << endl;
    cout << "Minimum of three numbers: " << minVal(10, 5, 2) << endl;

    return 0;
}
