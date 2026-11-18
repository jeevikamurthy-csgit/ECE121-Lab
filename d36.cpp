#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> frequency;
    string word;
    string mostFrequentWord;
    int highestCount = 0;

    while (cin >> word) {
        int count = ++frequency[word];

        if (count > highestCount) {
            highestCount = count;
            mostFrequentWord = word;
        }
    }

    if (frequency.empty()) {
        cout << "No words were entered.\n";
        return 0;
    }

    cout << "\nWord counts:\n";
    for (const auto& entry : frequency) {
        cout << entry.first << ": " << entry.second << '\n';
    }

    cout << "Most frequent word: " << mostFrequentWord
         << " (" << highestCount << " occurrences)\n";

    return 0;
}
