#include <iostream>
#include <vector>

// In C++ each function has a "signature" that contains:
//      - The function name
//      - The number of parameters
//      - The type of parameters
// IMPORTANT! The return type is *not* part of the signature

// In C++ two functions with different signature are
// different functions, even if they have the same name
// This is called "overloading"

// Signature: print(int)
void print(int value) {
    std::cout << "INTEGER: " << value << std::endl;
}

// Signature: print(int, int)
void print(int value, int count) {
    std::cout << "COUNT";
    for (int i = 0; i < count; i++) {
        std::cout << ' ' << value;
    }
    std::cout << std::endl;
}

// Signature print(const std::string&)
void print(const std::string &value) {
    std::cout << "STRING: " << value << std::endl;
}

// Signature print(const std::vector<T>)
template<class T>
void print(const std::vector<T> &value) {
    std::cout << "VECTOR";
    for (int i = 0; i < value.size(); i++) {
        std::cout << ' ' << value[i];
    }
    std::cout << std::endl;
}


int main() {
    print(5);
    print("Hallo Frank");
    print(3, 8);

    std::vector<int> data = {1, 2, 3, 4, 5};
    print(data);

    std::vector<double> data2 = {1.2, 2.3, 3.4, 4.5, 5.6};
    print(data2);
    return 0;
}
