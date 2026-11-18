#include <iostream>
#include <stdexcept>

class Stack {
private:
    int* data;
    int capacity;
    int topIndex;

    void grow() {
        int newCapacity = capacity * 2;
        int* newData = new int[newCapacity];

        for (int i = 0; i <= topIndex; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    explicit Stack(int initialCapacity = 4)
        : capacity(initialCapacity), topIndex(-1) {
        if (capacity <= 0) {
            throw std::invalid_argument("Capacity must be positive");
        }
        data = new int[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(int value) {
        if (topIndex + 1 == capacity) {
            grow();
        }
        data[++topIndex] = value;
    }

    int pop() {
        if (topIndex == -1) {
            throw std::runtime_error("Cannot pop from an empty stack");
        }
        return data[topIndex--];
    }

    bool empty() const {
        return topIndex == -1;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    while (!stack.empty()) {
        std::cout << stack.pop() << '\n';
    }
}
