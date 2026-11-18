#include <iostream>
using namespace std;

class Order {
private:
    static int nextId;
    int id;

public:
    Order() {
        id = nextId++;
    }

    int getId() const {
        return id;
    }
};

// Define and initialize the static member
int Order::nextId = 1001;

int main() {
    Order first;
    Order second;
    Order third;

    cout << "Order ID: " << first.getId() << '\n';
    cout << "Order ID: " << second.getId() << '\n';
    cout << "Order ID: " << third.getId() << '\n';

    return 0;
}
