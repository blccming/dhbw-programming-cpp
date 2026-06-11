// *** Aufgabe ***

// Implementieren Sie eine Klasse Gameboard, die ein Spielfeld für ein Spiel
// repräsentiert (quadratisch). Die Größe des Spielfelds soll dem Konstruktor übergeben
// werden. Das Spielfeld soll beliebige Zeichen (char) speichern können.

// Im Konstruktor soll das Spielfeld initialisiert werden. Alle Felder sollen
// den Wert ' ' (Leerzeichen) enthalten.

// Die Spalten des Spielfelds werden mit den Zeichen A, B, C, ... benannt.
// Die Zeilen des Spielfelds werden mit den Zahlen 1, 2, 3, ... benannt.
// Achtung: Die Indizierung der Zeilen beginnt bei 1, nicht bei 0!

// Implementieren Sie die Methode void print(), die das Spielfeld auf der
// Console ausgibt. Dabei sollen die Spalten und Zeilen beschriftet sein.

// Implementieren Sie die Methode void set(int row, char col, char value), die
// den Wert value an der Position (row, col) speichert.

// Implementieren Sie die Methode char get(int row, char col), die den Wert an
// der Position (row, col) zurückgibt.

// Implementieren Sie eine Main-Funktion, die ein 5x5 Spielfeld erstellt und
// dieses auf der Console ausgibt. Setzen Sie dann ein paar Werte und geben Sie
// das Spielfeld erneut aus.

#include "gameboard.h"
#include <iostream>

int main() {
    auto board = Gameboard(10);
    board.print();

    board.set(1, 'A', 'X');
    board.set(10, 'J', 'X');
    board.set(5, 'E', 'X');
    board.set(6, 'F', 'X');

    std::cout << "An 1/A: " << board.get(1, 'A') << std::endl
    << "An 2/A: " << board.get(2, 'A') << std::endl;

    board.print();
    return 0;
}
