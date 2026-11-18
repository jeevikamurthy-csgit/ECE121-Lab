#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

const int ITERATIONS = 100000;
mutex counterMutex;

void incrementWithoutLock(int& counter) {
    for (int i = 0; i < ITERATIONS; ++i) {
        ++counter; // Data race when called by multiple threads
    }
}

void incrementWithLock(int& counter) {
    for (int i = 0; i < ITERATIONS; ++i) {
        lock_guard<mutex> lock(counterMutex);
        ++counter;
    }
}

int main() {
    const int RUNS = 5;

    cout << "Without lock:\n";
    for (int run = 1; run <= RUNS; ++run) {
        int counter = 0;

        thread first(incrementWithoutLock, ref(counter));
        thread second(incrementWithoutLock, ref(counter));

        first.join();
        second.join();

        cout << "Run " << run << ": " << counter
             << " (expected " << 2 * ITERATIONS << ")\n";
    }

    cout << "\nWith lock_guard:\n";
    for (int run = 1; run <= RUNS; ++run) {
        int counter = 0;

        thread first(incrementWithLock, ref(counter));
        thread second(incrementWithLock, ref(counter));

        first.join();
        second.join();

        cout << "Run " << run << ": " << counter << '\n';
    }

    return 0;
}
