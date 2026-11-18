#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T value;
        Node* next;

        explicit Node(const T& item) : value(item), next(nullptr) {}
    };

    Node* first;
    Node* last;

public:
    Queue() : first(nullptr), last(nullptr) {}

    // Avoid shallow copies of the linked nodes.
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    ~Queue() {
        while (first != nullptr) {
            Node* oldFirst = first;
            first = first->next;
            delete oldFirst;
        }
    }

    void enqueue(const T& value) {
        Node* newNode = new Node(value);

        if (last == nullptr) {
            first = last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    T dequeue() {
        if (first == nullptr) {
            throw underflow_error("Cannot dequeue from an empty queue");
        }

        Node* oldFirst = first;
        T value = oldFirst->value;
        first = first->next;

        if (first == nullptr) {
            last = nullptr;
        }

        delete oldFirst;
        return value;
    }

    T& front() {
        if (first == nullptr) {
            throw underflow_error("Queue is empty");
        }
        return first->value;
    }

    bool empty() const {
        return first == nullptr;
    }
};

int main() {
    Queue<string> names;

    names.enqueue("Asha");
    names.enqueue("Ravi");
    names.enqueue("Maya");

    cout << "Front: " << names.front() << '\n';
    cout << "Removed: " << names.dequeue() << '\n';
    cout << "New front: " << names.front() << '\n';

    return 0;
}
