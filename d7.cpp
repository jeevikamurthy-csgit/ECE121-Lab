#include <iostream>
using namespace std;

class Counter {
private:
    static int totalCreated;
    static int currentlyAlive;

public:
    Counter() {
        ++totalCreated;
        ++currentlyAlive;
    }

    ~Counter() {
        --currentlyAlive;
    }

    static void showCounts() {
        cout << "Total created: " << totalCreated << '\n';
        cout << "Currently alive: " << currentlyAlive << '\n';
    }
};

// Define static members outside the class
int Counter::totalCreated = 0;
int Counter::currentlyAlive = 0;

int main() {
    Counter first;
    Counter::showCounts();

    {
        Counter second;
        Counter third;
        cout << "\nInside the block:\n";
        Counter::showCounts();
    }

    cout << "\nAfter the block:\n";
    Counter::showCounts();

    return 0;
}
