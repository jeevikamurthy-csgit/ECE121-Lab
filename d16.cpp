
#include <iostream>
using namespace std;

class Rectangle {
private:
    double length, width;

public:
    void setLength(double l) {
        if (l >= 0)
            length = l;
        else
            length = 0;
    }

    void setWidth(double w) {
        if (w >= 0)
            width = w;
        else
            width = 0;
    }

    double area() {
        return length * width;
    }

    double perimeter() {
        return 2 * (length + width);
    }
};

int main() {
    Rectangle r;

    r.setLength(5);
    r.setWidth(3);

    cout << "Area: " << r.area() << endl;
    cout << "Perimeter: " << r.perimeter() << endl;

    return 0;
}
