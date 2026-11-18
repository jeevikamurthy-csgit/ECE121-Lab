#include <iostream>
using namespace std;

class Tracer {
    int id;

public:
    Tracer(int i) : id(i) {
        cout << "Construct #" << id << endl;
    }

    ~Tracer() {
        cout << "Destruct #" << id << endl;
    }
};

int main() {
    cout << "Enter loop\n";

    for (int i = 1; i <= 3; ++i) {
        Tracer* t = new Tracer(i);

        cout << "...working...\n";

        delete t;  // Calls the destructor and frees the memory
    }

    cout << "Left loop\n";
    return 0;
}
