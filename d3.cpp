
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string s, word;
    string words[100];
    int count = 0;

    cout << "Enter a sentence: ";
    getline(cin, s);

    stringstream ss(s);

    while (ss >> word) {
        words[count] = word;
        count++;
    }

    for (int i = count - 1; i >= 0; i--) {
        cout << words[i] << " ";
    }

    cout << endl;

    return 0;
}
