#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
void swapVals(T& first, T& second) {
    T temporary = first;
    first = second;
    second = temporary;
}

template <typename T>
T findMax(const T arr[], int n) {
    if (n <= 0) {
        throw invalid_argument("Array must contain at least one element");
    }

    T maximum = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }
    return maximum;
}

int main() {
    int a = 10, b = 20;
    swapVals(a, b);
    cout << "Swapped integers: " << a << ", " << b << '\n';

    int integers[] = {4, 9, 2, 7};
    cout << "Largest integer: " << findMax(integers, 4) << '\n';

    double x = 1.5, y = 3.8;
    swapVals(x, y);
    cout << "Swapped doubles: " << x << ", " << y << '\n';

    double decimals[] = {2.4, 8.1, 5.6};
    cout << "Largest double: " << findMax(decimals, 3) << '\n';

    return 0;
}
