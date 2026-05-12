#include <iostream>

// WRONG! Call by value!
// Only the local variables a and b are swapped
// The variables in main() are unchanged
void swapA(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swapB(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// C++ style call by reference
// The final generated code s the same as for swapB
// using pointers, but the synta is much mor elegant
void swapC(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}


// NOTE: differences between these implementations are important to know for the exam!!
int main() {
    int a = 5, b = 7;

    std::cout << "Initial values: a=" << a << ", b=" << b << std::endl;
    swapA(a, b);
    std::cout << "After swapA:    a=" << a << ", b=" << b << std::endl;
    swapB(&a, &b);
    std::cout << "After swapB:    a=" << a << ", b=" << b << std::endl;
    swapC(a, b);
    std::cout << "After swapC:    a=" << a << ", b=" << b << std::endl;

    return 0;
}
