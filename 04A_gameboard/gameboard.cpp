#include "gameboard.h"
#include <iostream>
#include <iomanip>

void Gameboard::print() const {
    // first print top row
    std::cout << "   | ";
    for (int i = 0; i < mSize; i++) {
        std::cout << char(i + 65) << " | ";
    }
    std::cout << std::endl;

    // print all rows below
    for (int i = 0; i < mSize; i++) {
        std::cout << std::setw(2) << i+1 << " | ";
        for (int j = 0; j < mSize; j++) {
            std::cout <<  mBoard[i][j] << " | ";
        }
        std::cout << std::endl;
    }
}
