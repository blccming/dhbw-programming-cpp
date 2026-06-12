#include <initializer_list>
#include <iostream>
#include <ostream>
#include <vector>
#include <cassert>

template<typename T>
class Array {
    public:
        Array(std::initializer_list<T> init) {
            assert(init.size() == 5);
            std::copy(init.begin(), init.end(), mData);
        }

        int size() const {
            return 5;
        }

        const T operator[](int index) const {
            return mData[index];
        }

    private:
        T mData[5];
};

// output operator for any std::vector
template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &value) {
    out << "Vector:";
    for (auto el: value) {
        out << ' ' << el;
    }
    return out;
}

// output operator for any Array
template<typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &value) {
    out << "Array:";
    for (int i=0; i < value.size(); i++) {
        out << ' ' << value[i];
    }
    return out;
}

// generic print function for any type that has an output operator
template<typename T>
void print(const T &value) {
    std::cout << value << std::endl;
}

int main() {
    print<int>(5); // explicit type parameter
    print(3.141); // type parameter deduced implicitly
    print("Hello Frank");

    std::vector<int> data = { 1, 2, 3, 4, 5};
    print(data);


    std::vector<std::string> strings = { "one", "two", "three", "four", "five" };
    print(strings);

    Array<int> intArray = { 6, 7, 8, 9, 10 };
    print(intArray);

    Array<std::string> strArray = { "six", "seven", "eight", "nine", "ten" };
    print(strArray);

    return 0;
}
