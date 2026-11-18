#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    string color;

public:
    Shape(const string& shapeColor) : color(shapeColor) {
        cout << "Shape constructor: color = " << color << '\n';
    }
};

class Polygon : public Shape {
protected:
    int sides;

public:
    Polygon(const string& shapeColor, int sideCount)
        : Shape(shapeColor), sides(sideCount) {
        cout << "Polygon constructor: sides = " << sides << '\n';
    }
};

class Rectangle : public Polygon {
private:
    double width;

public:
    Rectangle(const string& shapeColor, int sideCount, double rectangleWidth)
        : Polygon(shapeColor, sideCount), width(rectangleWidth) {
        cout << "Rectangle constructor: width = " << width << '\n';
    }

    void printDetails() const {
        cout << "\nRectangle details\n"
             << "Color: " << color << '\n'
             << "Sides: " << sides << '\n'
             << "Width: " << width << '\n';
    }
};

int main() {
    Rectangle rectangle("Blue", 4, 5.5);
    rectangle.printDetails();

    return 0;
}
