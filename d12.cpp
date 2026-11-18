#include <iostream>
#include <stdexcept>
using namespace std;

class SafeArray {
private:
    int* data;
    int size;

public:
    explicit SafeArray(int arraySize) : size(arraySize) {
        if (size <= 0) {
            throw invalid_argument("Array size must be positive");
        }
        data = new int[size]{};
    }

    // Deep copy constructor
    SafeArray(const SafeArray& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Deep copy assignment
    SafeArray& operator=(const SafeArray& other) {
        if (this != &other) {
            int* newData = new int[other.size];
            for (int i = 0; i < other.size; ++i) {
                newData[i] = other.data[i];
            }

            delete[] data;
            data = newData;
            size = other.size;
        }
        return *this;
    }

    ~SafeArray() {
        delete[] data;
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Array index out of range");
        }
        return data[index];
    }

    const int& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Array index out of range");
        }
        return data[index];
    }

    int getSize() const {
        return size;
    }
};

int main() {
    try {
        SafeArray numbers(3);

        numbers[0] = 10;
        numbers[1] = 20;
        numbers[2] = 30;

        for (int i = 0; i < numbers.getSize(); ++i) {
            cout << numbers[i] << ' ';
        }
        cout << '\n';

        cout << numbers[5] << '\n'; // Throws an out-of-range error
    } catch (const out_of_range& error) {
        cout << "Error: " << error.what() << '\n';
    }

    return 0;
}
