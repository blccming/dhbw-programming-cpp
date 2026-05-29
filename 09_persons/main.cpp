#include <iostream>

#include "student.h"


void testStudents() {
    // ERROR: The constructor "Person" is protected making the
    // class "abstract". We cannot create objects directly.
    // Person p1("Nobody");

    Student s1("Hans Klein");
    Student s2("Hugo Gross", "TINF25B3");
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
}


int main() {
    std::cout << "Persons in C++" << std::endl;

    testStudents();

    return 0;
}
