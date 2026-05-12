// *** Aufgabe ***

// Lesen Sie vom Benutzer das Startkapital (double), den Zinssatz (double) und
// die Anzahl der Jahre (int) ein.

// Geben Sie den Betrag mit Zinsen nach den angegebenen Jahren aus.

// Tip: Nutzen Sie die Funktion pow() aus der Standard-C-Library
#include <cmath>
#include <iostream>

int main() {
    double kapital, zinssatz;
    int jahre;

    std::cout << "Geben Sie Ihr Startkapital ein (€): ";
    std::cin >> kapital;
    std::cout << std::endl;

    std::cout << "Geben Sie Ihren Zinsatz ein (%): ";
    std::cin >> zinssatz;
    std::cout << std::endl;

    std::cout << "Geben Sie die Anzahl der zu Jahre ein: ";
    std::cin >> jahre;
    std::cout << std::endl;

    kapital = kapital * std::pow(1 + (zinssatz / 100), jahre);

    std::cout << "Berechnetes Endkapital: " << kapital << std::endl;
}
