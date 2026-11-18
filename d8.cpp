#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

public:
    Time(int h, int m) : hours(h), minutes(m) {}

    void display() const {
        cout << setfill('0') << setw(2) << hours
             << ':' << setw(2) << minutes
             << setfill(' ');
    }

    friend Time laterOf(const Time& first, const Time& second);
};

Time laterOf(const Time& first, const Time& second) {
    int firstTotalMinutes = first.hours * 60 + first.minutes;
    int secondTotalMinutes = second.hours * 60 + second.minutes;

    if (firstTotalMinutes >= secondTotalMinutes) {
        return first;
    }
    return second;
}

int main() {
    Time morning(9, 45);
    Time afternoon(14, 20);

    cout << "First time: ";
    morning.display();

    cout << "\nSecond time: ";
    afternoon.display();

    Time later = laterOf(morning, afternoon);
    cout << "\nLater time: ";
    later.display();

    cout << '\n';
    return 0;
}
