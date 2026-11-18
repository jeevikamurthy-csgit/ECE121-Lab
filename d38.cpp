#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual string name() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double r) : radius(r) {}

    double area() const override {
        return acos(-1.0) * radius * radius;
    }

    string name() const override {
        return "Circle";
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() const override {
        return length * width;
    }

    string name() const override {
        return "Rectangle";
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double area() const override {
        return 0.5 * base * height;
    }

    string name() const override {
        return "Triangle";
    }
};

int main() {
    vector<unique_ptr<Shape>> shapes;
    string shapeName;

    while (true) {
        cout << "Enter shape (circle, rectangle, triangle, or done): ";
        cin >> shapeName;

        for (char& ch : shapeName) {
            ch = static_cast<char>(tolower(static_cast<unsigned char>(ch)));
        }

        if (shapeName == "done") {
            break;
        }

        if (shapeName == "circle") {
            double radius;
            cout << "Enter radius: ";
            cin >> radius;
            shapes.push_back(unique_ptr<Shape>(new Circle(radius)));
        } else if (shapeName == "rectangle") {
            double length, width;
            cout << "Enter length and width: ";
            cin >> length >> width;
            shapes.push_back(unique_ptr<Shape>(new Rectangle(length, width)));
        } else if (shapeName == "triangle") {
            double base, height;
            cout << "Enter base and height: ";
            cin >> base >> height;
            shapes.push_back(unique_ptr<Shape>(new Triangle(base, height)));
        } else {
            cout << "Unknown shape. Try again.\n";
        }
    }

    cout << "\nCreated shapes:\n";
    for (const auto& shape : shapes) {
        cout << shape->name() << " area: " << shape->area() << '\n';
    }

    return 0;
}
