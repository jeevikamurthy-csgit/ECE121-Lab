#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int main() {
    ifstream input("nums.txt");

    if (!input) {
        cerr << "Could not open nums.txt\n";
        return 1;
    }

    int value;
    int count = 0;
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    long long sum = 0;

    while (input >> value) {
        ++count;
        sum += value;

        if (value < minimum) minimum = value;
        if (value > maximum) maximum = value;
    }

    if (count == 0) {
        cout << "No integers found in nums.txt\n";
        return 0;
    }

    cout << "Count: " << count << '\n'
         << "Sum: " << sum << '\n'
         << "Minimum: " << minimum << '\n'
         << "Maximum: " << maximum << '\n';

    return 0;
}
