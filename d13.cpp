
#include <iostream>
using namespace std;

// Cube
double volume(double a) {
    return a * a * a;
}

// Cuboid
double volume(double l, double b, double h) {
    return l * b * h;
}

// Cylinder
double volume(double r, double h) {
    return 3.14 * r * r * h;
}

int main() {
    cout << "Volume of cube: " << volume(5) << endl;
    cout << "Volume of cuboid: " << volume(2, 3, 4) << endl;
    cout << "Volume of cylinder: " << volume(3, 5) << endl;

    return 0;
}
