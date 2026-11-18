#include <iostream>
using namespace std;

class Base {
public:
#ifdef FIXED
    virtual ~Base() {
#else
    ~Base() {
#endif
        cout << "Base destructor\n";
    }
};

class Derived : public Base {
private:
    int* data;

public:
    Derived() : data(new int[100]) {
        cout << "Derived allocated memory\n";
    }

    ~Derived() {
        delete[] data;
        cout << "Derived destructor: memory released\n";
    }
};

int main() {
    Base* object = new Derived;
    delete object;
    return 0;
}
