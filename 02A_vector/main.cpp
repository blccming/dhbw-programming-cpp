// *** Aufgabe ***

// Lesen Sie vom Benutzer eine Folge von ganzen Zahlen (int) ein, bis entweder
// keine Zahlen mehr verfügbar sind (EOF) oder eine negative Zahl eingegeben wird.

// Übergeben Sie die eingelesenen Zahlen an eine Funktion printReverse, die die
// Zahlen in umgekehrter Reihenfolge ausgibt.

#include <vector>
#include <iostream>

void printReverse(const std::vector<int>& values) {
    auto vec = values;
    while (!vec.empty()) {
        std::cout << vec.back() << std::endl;
        vec.pop_back();
    }
}

int main() {

    std::vector<int> values;

    int input;
    while ((std::cin >> input) && (input >= 0)) {
        values.push_back(input);
    }

    printReverse(values);
    printReverse(values);

    return 0;
}
