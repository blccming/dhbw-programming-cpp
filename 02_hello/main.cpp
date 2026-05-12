#include <iostream>

// Makes all sybols(classes, functions, ...) from namespace std
// available without using the explicit prefix "std::"
using namespace std;

int main () {
    // Use object "cout" from namespace "std" to print to console
    // std::endl means "end line"
    cout << "Hello World" << endl;
    return 0;
}
