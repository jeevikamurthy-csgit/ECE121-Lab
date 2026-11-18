#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

class Stack {
private:
    unique_ptr<int[]> data;
    int capacity;
    int topIndex;

    void grow() {
        int newCapacity = capacity * 2;
        unique_ptr<int[]> newData(new int[newCapacity]);

        for (int i = 0; i <= topIndex; ++i) {
            newData[i] = data[i];
        }

        data = move(newData);
        capacity = newCapacity;
    }

public:
    explicit Stack(int initialCapacity = 4)
        : data(new int[initialCapacity]),
          capacity(initialCapacity),
          topIndex(-1) {
        if (initialCapacity <= 0) {
            throw invalid_argument("Capacity must be positive");
        }
    }

    void push(int value) {
        if (topIndex + 1 == capacity) {
            grow();
        }
        data[++topIndex] = value;
    }

    int pop() {
        if (topIndex == -1) {
            throw underflow_error("Stack is empty");
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
        cout << stack.pop() << '\n';
    }

    return 0;
}
