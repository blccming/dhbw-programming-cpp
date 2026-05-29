#include <iostream>
#include <string>
#include <vector>

// In C++ each function has a "signature" that contains:
//    - The function name
//    - The number of parameters
//    - The type of parameters
// IMPORTANT! The return type is *not* part of the signature

// In C++ two functions with different signature are
// different functions, even if they have the same name.
// This is called "overloading".

// Signature: print(int)
void print(int value) {
    std::cout << "INTEGER: " << value << std::endl;
}

// Signature: print(int, int)
void print(int value, int count) {
    std::cout << "COUNT:";
    for (int i=0; i<count; i++) {
        std::cout << ' ' << value;
    }
    std::cout << std::endl;
}

// Signature print(const std::string&)
void print(const std::string &value) {
    std::cout << "STRING: " << value << std::endl;
}

// Signature print(const std::vector<T>&)
template<class T>
void print(const std::vector<T> &value) {
    std::cout << "VECTOR:";
    for (int i=0; i<value.size(); i++) {
        std::cout << ' ' << value[i];
    }
    std::cout << std::endl;
}

// With count = 1 we set a default value
// Signature 1: print(double)
// Signature 2: print(double, int)
void print(double value, int count = 1) {
    std::cout << "DOUBLE:";
    for (int i=0; i<count; i++)
        std::cout << ' ' << value;
    std::cout << std::endl;
}

// Signature: print(double)
// ERROR! Conflicts with function above
// Note: the return type is *not* part of the signature
// int print(double value) {
// }

// We can add multiple default values to one function.
// Signature 1: test(int, int)
// Signature 2: test(int, int, int)
// Signature 3: test(int, int, int, int)
void test(int a, int b, int c = 3, int d = 4) {
}

// ERROR: if a parameter has a default value, all following
// parameters need to have a default value, too.
// void test(int a, int b, int c = 3, int d) {
// }

int main() {
    print(5);
    print("Hello Frank!");
    print(6, 3);

    std::vector<int> data = { 1, 2, 3, 4, 5 };
    print(data);

    std::vector<double> data2 = { 1.2, 2.3, 3.4, 4.5, 5.6 };
    print(data2);

    // Both statements call the same print(...) function,
    // but the first one uses the default count = 1
    print(3.141);
    print(3.141, 5);

    return 0;
}
