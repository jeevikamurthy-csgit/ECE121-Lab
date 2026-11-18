#include <iostream>
#include <stdexcept>
using namespace std;

class Overflow : public runtime_error {
public:
    Overflow() : runtime_error("Stack is full") {}
};

class Underflow : public runtime_error {
public:
    Underflow() : runtime_error("Stack is empty") {}
};

class Stack {
private:
    static const int CAPACITY = 3;
    int items[CAPACITY];
    int topIndex;

public:
    Stack() : topIndex(-1) {}

    void push(int value) {
        if (topIndex == CAPACITY - 1) {
            throw Overflow();
        }
        items[++topIndex] = value;
    }

    int pop() {
        if (topIndex == -1) {
            throw Underflow();
        }
        return items[topIndex--];
    }
};

int main() {
    Stack stack;

    try {
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40); // Throws Overflow
    } catch (const Overflow& error) {
        cout << "Overflow error: " << error.what() << '\n';
    }

    try {
        cout << "Popped: " << stack.pop() << '\n';
        cout << "Popped: " << stack.pop() << '\n';
        cout << "Popped: " << stack.pop() << '\n';
        cout << "Popped: " << stack.pop() << '\n'; // Throws Underflow
    } catch (const Underflow& error) {
        cout << "Underflow error: " << error.what() << '\n';
    }

    return 0;
}
