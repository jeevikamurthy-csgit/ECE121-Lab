#include <iostream>
#include <stdexcept>

class Matrix {
private:
    int rows;
    int cols;
    int* data;

public:
    Matrix(int m, int n) : rows(m), cols(n), data(nullptr) {
        if (m <= 0 || n <= 0) {
            throw std::invalid_argument("Matrix dimensions must be positive");
        }
        data = new int[rows * cols]{};
    }

    // Deep copy constructor
    Matrix(const Matrix& other)
        : rows(other.rows), cols(other.cols),
          data(new int[other.rows * other.cols]) {
        for (int i = 0; i < rows * cols; ++i) {
            data[i] = other.data[i];
        }
    }

    // Deep copy assignment
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            int* newData = new int[other.rows * other.cols];
            for (int i = 0; i < other.rows * other.cols; ++i) {
                newData[i] = other.data[i];
            }

            delete[] data;
            rows = other.rows;
            cols = other.cols;
            data = newData;
        }
        return *this;
    }

    ~Matrix() {
        delete[] data;
    }

    int& at(int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            throw std::out_of_range("Matrix index out of range");
        }
        return data[row * cols + col];
    }

    void print() const {
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                std::cout << data[r * cols + c] << ' ';
            }
            std::cout << '\n';
        }
    }
};

int main() {
    Matrix first(2, 3);
    first.at(0, 0) = 10;
    first.at(1, 2) = 25;

    Matrix copy = first; // Deep copy
    copy.at(0, 0) = 99;

    std::cout << "Original:\n";
    first.print();

    std::cout << "Copy:\n";
    copy.print();
}
